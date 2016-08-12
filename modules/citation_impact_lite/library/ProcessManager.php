<?php

/************************************************************************************************
 * // Name:    ProcessManager.php
 * // Author:    Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    Process manager class
 ************************************************************************************************/

class ProcessManager {
    public $executable       = "php";	//the system command to call
    public $root             = "";		//the root path
    public $processes        = 3;		//max concurrent processes
    public $sleep_time       = 2;		//time between processes
    public $show_output      = false;	//where to show the output or not

    private $running          = array();//the list of scripts currently running
    private $scripts          = array();//the list of scripts - populated by addScript
    private $processesRunning = 0;		//count of processes running

    function addScript($script, $arg, $max_execution_time = 300)
    {
        $this->scripts[] = array("script_name" => $script, "arg"=>$arg, "max_execution_time" => $max_execution_time);
    }

    function exec()
    {
        $i = 0;
        for(;;)
        {
            // Fill up the slots
            while (($this->processesRunning<$this->processes) and ($i<count($this->scripts)))
            {
                if($this->show_output)
                {
                    ob_start();
                    echo "<span style='color: orange;'>Adding script: ".$this->scripts[$i]["script_name"]."</span><br />";
                    ob_flush();
                    flush();
                }
                $this->running[] =& new Process($this->executable, $this->root, $this->scripts[$i]["script_name"], $this->scripts[$i]["arg"], $this->scripts[$i]["max_execution_time"]);
                $this->processesRunning++;
                $i++;
            }

            // Check if done
            if (($this->processesRunning==0) and ($i>=count($this->scripts))) {
                break;
            }

            // sleep, this duration depends on your script execution time, the longer execution time, the longer sleep time
            sleep($this->sleep_time);

            // check what is done
            foreach ($this->running as $key => $val)
            {

                if (!$val->isRunning() or $val->isOverExecuted())
                {
                    if($this->show_output)
                    {
                        ob_start();
                        if (!$val->isRunning())
                        {
                            echo "<span style='color: green;'>Done: ".$val->script."</span><br />";
                        }
                        else
                        {
                            echo "<span style='color: red;'>Killed: ".$val->script."</span><br />";
                        }
                        ob_flush();
                        flush();
                    }
                    proc_close($val->resource);
                    unset($this->running[$key]);
                    $this->processesRunning--;
                }
            }
        }
    }
}

class Process {
    public $resource;
    public $pipes;
    public $script;
    public $arg;
    public $max_execution_time;
    public $start_time;

    function __construct(&$executable, &$root, $script, $arg, $max_execution_time)
    {
        $this->script = $script;
        $this->arg = $arg;
        $this->max_execution_time = $max_execution_time;
        $descriptorspec    = array(
            0 => array('pipe', 'r'),
            1 => array('pipe', 'w'),
            2 => array('pipe', 'w')
        );
        $this->resource    = proc_open($executable." ".$root.$this->script . " ". $this->arg, $descriptorspec, $this->pipes, null, $_ENV);
        // $this->start_time = mktime();
        $this->start_time = time();
    }

    // is still running?
    function isRunning()
    {
        $status = proc_get_status($this->resource);
        return $status["running"];
    }

    // long execution time, proccess is going to be killer
    function isOverExecuted()
    {
        if ($this->start_time+$this->max_execution_time<time()) return true;
        else return false;
    }
}

?>