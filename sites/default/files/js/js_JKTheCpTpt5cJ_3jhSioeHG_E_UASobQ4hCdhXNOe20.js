(function ($) {

Drupal.behaviors.facetapi = {
  attach: function(context, settings) {
    // Iterates over facet settings, applies functionality like the "Show more"
    // links for block realm facets.
    // @todo We need some sort of JS API so we don't have to make decisions
    // based on the realm.
    if (settings.facetapi) {
      for (var index in settings.facetapi.facets) {
        if (null != settings.facetapi.facets[index].makeCheckboxes) {
          Drupal.facetapi.makeCheckboxes(settings.facetapi.facets[index].id);
        }
        if (null != settings.facetapi.facets[index].limit) {
          // Applies soft limit to the list.
          Drupal.facetapi.applyLimit(settings.facetapi.facets[index]);
        }
      }
    }
  }
}

/**
 * Class containing functionality for Facet API.
 */
Drupal.facetapi = {}

/**
 * Applies the soft limit to facets in the block realm.
 */
Drupal.facetapi.applyLimit = function(settings) {
  if (settings.limit > 0 && !$('ul#' + settings.id).hasClass('facetapi-processed')) {
    // Only process this code once per page load.
    $('ul#' + settings.id).addClass('facetapi-processed');

    // Ensures our limit is zero-based, hides facets over the limit.
    var limit = settings.limit - 1;
    $('ul#' + settings.id).find('li:gt(' + limit + ')').hide();

    // Adds "Show more" / "Show fewer" links as appropriate.
    $('ul#' + settings.id).filter(function() {
      return $(this).find('li').length > settings.limit;
    }).each(function() {
      $('<a href="#" class="facetapi-limit-link"></a>').text(Drupal.t(settings.showMoreText)).click(function() {
        if ($(this).siblings().find('li:hidden').length > 0) {
          $(this).siblings().find('li:gt(' + limit + ')').slideDown();
          $(this).addClass('open').text(Drupal.t(settings.showFewerText));
        }
        else {
          $(this).siblings().find('li:gt(' + limit + ')').slideUp();
          $(this).removeClass('open').text(Drupal.t(settings.showMoreText));
        }
        return false;
      }).insertAfter($(this));
    });
  }
}

/**
 * Constructor for the facetapi redirect class.
 */
Drupal.facetapi.Redirect = function(href) {
  this.href = href;
}

/**
 * Method to redirect to the stored href.
 */
Drupal.facetapi.Redirect.prototype.gotoHref = function() {
  window.location.href = this.href;
}

/**
 * Turns all facet links into checkboxes.
 * Ensures the facet is disabled if a link is clicked.
 */
Drupal.facetapi.makeCheckboxes = function(facet_id) {
  var $facet = $('#' + facet_id),
      $links = $('a.facetapi-checkbox', $facet);

  // Find all checkbox facet links and give them a checkbox.
  $links.once('facetapi-makeCheckbox').each(Drupal.facetapi.makeCheckbox);
  $links.once('facetapi-disableClick').click(function (e) {
    Drupal.facetapi.disableFacet($facet);
  });
}

/**
 * Disable all facet links and checkboxes in the facet and apply a 'disabled'
 * class.
 */
Drupal.facetapi.disableFacet = function ($facet) {
  $facet.addClass('facetapi-disabled');
  $('a.facetapi-checkbox').click(Drupal.facetapi.preventDefault);
  $('input.facetapi-checkbox', $facet).attr('disabled', true);
}

/**
 * Event listener for easy prevention of event propagation.
 */
Drupal.facetapi.preventDefault = function (e) {
  e.preventDefault();
}

/**
 * Replace an unclick link with a checked checkbox.
 */
Drupal.facetapi.makeCheckbox = function() {
  var $link = $(this),
      active = $link.hasClass('facetapi-active');

  if (!active && !$link.hasClass('facetapi-inactive')) {
    // Not a facet link.
    return;
  }

  // Derive an ID and label for the checkbox based on the associated link.
  // The label is required for accessibility, but it duplicates information
  // in the link itself, so it should only be shown to screen reader users.
  var id = this.id + '--checkbox',
      description = $link.find('.element-invisible').html(),
      label = $('<label class="element-invisible" for="' + id + '">' + description + '</label>'),
      checkbox = $('<input type="checkbox" class="facetapi-checkbox" id="' + id + '" />'),
      // Get the href of the link that is this DOM object.
      href = $link.attr('href'),
      redirect = new Drupal.facetapi.Redirect(href);

  checkbox.click(function (e) {
    Drupal.facetapi.disableFacet($link.parents('ul.facetapi-facetapi-checkbox-links'));
    redirect.gotoHref();
  });

  if (active) {
    checkbox.attr('checked', true);
    // Add the checkbox and label, hide the link.
    $link.before(label).before(checkbox).hide();
  }
  else {
    $link.before(label).before(checkbox);
  }
}

})(jQuery);
;
//     Underscore.js 1.8.3
//     http://underscorejs.org
//     (c) 2009-2015 Jeremy Ashkenas, DocumentCloud and Investigative Reporters & Editors
//     Underscore may be freely distributed under the MIT license.
(function(){function n(n){function t(t,r,e,u,i,o){for(;i>=0&&o>i;i+=n){var a=u?u[i]:i;e=r(e,t[a],a,t)}return e}return function(r,e,u,i){e=b(e,i,4);var o=!k(r)&&m.keys(r),a=(o||r).length,c=n>0?0:a-1;return arguments.length<3&&(u=r[o?o[c]:c],c+=n),t(r,e,u,o,c,a)}}function t(n){return function(t,r,e){r=x(r,e);for(var u=O(t),i=n>0?0:u-1;i>=0&&u>i;i+=n)if(r(t[i],i,t))return i;return-1}}function r(n,t,r){return function(e,u,i){var o=0,a=O(e);if("number"==typeof i)n>0?o=i>=0?i:Math.max(i+a,o):a=i>=0?Math.min(i+1,a):i+a+1;else if(r&&i&&a)return i=r(e,u),e[i]===u?i:-1;if(u!==u)return i=t(l.call(e,o,a),m.isNaN),i>=0?i+o:-1;for(i=n>0?o:a-1;i>=0&&a>i;i+=n)if(e[i]===u)return i;return-1}}function e(n,t){var r=I.length,e=n.constructor,u=m.isFunction(e)&&e.prototype||a,i="constructor";for(m.has(n,i)&&!m.contains(t,i)&&t.push(i);r--;)i=I[r],i in n&&n[i]!==u[i]&&!m.contains(t,i)&&t.push(i)}var u=this,i=u._,o=Array.prototype,a=Object.prototype,c=Function.prototype,f=o.push,l=o.slice,s=a.toString,p=a.hasOwnProperty,h=Array.isArray,v=Object.keys,g=c.bind,y=Object.create,d=function(){},m=function(n){return n instanceof m?n:this instanceof m?void(this._wrapped=n):new m(n)};"undefined"!=typeof exports?("undefined"!=typeof module&&module.exports&&(exports=module.exports=m),exports._=m):u._=m,m.VERSION="1.8.3";var b=function(n,t,r){if(t===void 0)return n;switch(null==r?3:r){case 1:return function(r){return n.call(t,r)};case 2:return function(r,e){return n.call(t,r,e)};case 3:return function(r,e,u){return n.call(t,r,e,u)};case 4:return function(r,e,u,i){return n.call(t,r,e,u,i)}}return function(){return n.apply(t,arguments)}},x=function(n,t,r){return null==n?m.identity:m.isFunction(n)?b(n,t,r):m.isObject(n)?m.matcher(n):m.property(n)};m.iteratee=function(n,t){return x(n,t,1/0)};var _=function(n,t){return function(r){var e=arguments.length;if(2>e||null==r)return r;for(var u=1;e>u;u++)for(var i=arguments[u],o=n(i),a=o.length,c=0;a>c;c++){var f=o[c];t&&r[f]!==void 0||(r[f]=i[f])}return r}},j=function(n){if(!m.isObject(n))return{};if(y)return y(n);d.prototype=n;var t=new d;return d.prototype=null,t},w=function(n){return function(t){return null==t?void 0:t[n]}},A=Math.pow(2,53)-1,O=w("length"),k=function(n){var t=O(n);return"number"==typeof t&&t>=0&&A>=t};m.each=m.forEach=function(n,t,r){t=b(t,r);var e,u;if(k(n))for(e=0,u=n.length;u>e;e++)t(n[e],e,n);else{var i=m.keys(n);for(e=0,u=i.length;u>e;e++)t(n[i[e]],i[e],n)}return n},m.map=m.collect=function(n,t,r){t=x(t,r);for(var e=!k(n)&&m.keys(n),u=(e||n).length,i=Array(u),o=0;u>o;o++){var a=e?e[o]:o;i[o]=t(n[a],a,n)}return i},m.reduce=m.foldl=m.inject=n(1),m.reduceRight=m.foldr=n(-1),m.find=m.detect=function(n,t,r){var e;return e=k(n)?m.findIndex(n,t,r):m.findKey(n,t,r),e!==void 0&&e!==-1?n[e]:void 0},m.filter=m.select=function(n,t,r){var e=[];return t=x(t,r),m.each(n,function(n,r,u){t(n,r,u)&&e.push(n)}),e},m.reject=function(n,t,r){return m.filter(n,m.negate(x(t)),r)},m.every=m.all=function(n,t,r){t=x(t,r);for(var e=!k(n)&&m.keys(n),u=(e||n).length,i=0;u>i;i++){var o=e?e[i]:i;if(!t(n[o],o,n))return!1}return!0},m.some=m.any=function(n,t,r){t=x(t,r);for(var e=!k(n)&&m.keys(n),u=(e||n).length,i=0;u>i;i++){var o=e?e[i]:i;if(t(n[o],o,n))return!0}return!1},m.contains=m.includes=m.include=function(n,t,r,e){return k(n)||(n=m.values(n)),("number"!=typeof r||e)&&(r=0),m.indexOf(n,t,r)>=0},m.invoke=function(n,t){var r=l.call(arguments,2),e=m.isFunction(t);return m.map(n,function(n){var u=e?t:n[t];return null==u?u:u.apply(n,r)})},m.pluck=function(n,t){return m.map(n,m.property(t))},m.where=function(n,t){return m.filter(n,m.matcher(t))},m.findWhere=function(n,t){return m.find(n,m.matcher(t))},m.max=function(n,t,r){var e,u,i=-1/0,o=-1/0;if(null==t&&null!=n){n=k(n)?n:m.values(n);for(var a=0,c=n.length;c>a;a++)e=n[a],e>i&&(i=e)}else t=x(t,r),m.each(n,function(n,r,e){u=t(n,r,e),(u>o||u===-1/0&&i===-1/0)&&(i=n,o=u)});return i},m.min=function(n,t,r){var e,u,i=1/0,o=1/0;if(null==t&&null!=n){n=k(n)?n:m.values(n);for(var a=0,c=n.length;c>a;a++)e=n[a],i>e&&(i=e)}else t=x(t,r),m.each(n,function(n,r,e){u=t(n,r,e),(o>u||1/0===u&&1/0===i)&&(i=n,o=u)});return i},m.shuffle=function(n){for(var t,r=k(n)?n:m.values(n),e=r.length,u=Array(e),i=0;e>i;i++)t=m.random(0,i),t!==i&&(u[i]=u[t]),u[t]=r[i];return u},m.sample=function(n,t,r){return null==t||r?(k(n)||(n=m.values(n)),n[m.random(n.length-1)]):m.shuffle(n).slice(0,Math.max(0,t))},m.sortBy=function(n,t,r){return t=x(t,r),m.pluck(m.map(n,function(n,r,e){return{value:n,index:r,criteria:t(n,r,e)}}).sort(function(n,t){var r=n.criteria,e=t.criteria;if(r!==e){if(r>e||r===void 0)return 1;if(e>r||e===void 0)return-1}return n.index-t.index}),"value")};var F=function(n){return function(t,r,e){var u={};return r=x(r,e),m.each(t,function(e,i){var o=r(e,i,t);n(u,e,o)}),u}};m.groupBy=F(function(n,t,r){m.has(n,r)?n[r].push(t):n[r]=[t]}),m.indexBy=F(function(n,t,r){n[r]=t}),m.countBy=F(function(n,t,r){m.has(n,r)?n[r]++:n[r]=1}),m.toArray=function(n){return n?m.isArray(n)?l.call(n):k(n)?m.map(n,m.identity):m.values(n):[]},m.size=function(n){return null==n?0:k(n)?n.length:m.keys(n).length},m.partition=function(n,t,r){t=x(t,r);var e=[],u=[];return m.each(n,function(n,r,i){(t(n,r,i)?e:u).push(n)}),[e,u]},m.first=m.head=m.take=function(n,t,r){return null==n?void 0:null==t||r?n[0]:m.initial(n,n.length-t)},m.initial=function(n,t,r){return l.call(n,0,Math.max(0,n.length-(null==t||r?1:t)))},m.last=function(n,t,r){return null==n?void 0:null==t||r?n[n.length-1]:m.rest(n,Math.max(0,n.length-t))},m.rest=m.tail=m.drop=function(n,t,r){return l.call(n,null==t||r?1:t)},m.compact=function(n){return m.filter(n,m.identity)};var S=function(n,t,r,e){for(var u=[],i=0,o=e||0,a=O(n);a>o;o++){var c=n[o];if(k(c)&&(m.isArray(c)||m.isArguments(c))){t||(c=S(c,t,r));var f=0,l=c.length;for(u.length+=l;l>f;)u[i++]=c[f++]}else r||(u[i++]=c)}return u};m.flatten=function(n,t){return S(n,t,!1)},m.without=function(n){return m.difference(n,l.call(arguments,1))},m.uniq=m.unique=function(n,t,r,e){m.isBoolean(t)||(e=r,r=t,t=!1),null!=r&&(r=x(r,e));for(var u=[],i=[],o=0,a=O(n);a>o;o++){var c=n[o],f=r?r(c,o,n):c;t?(o&&i===f||u.push(c),i=f):r?m.contains(i,f)||(i.push(f),u.push(c)):m.contains(u,c)||u.push(c)}return u},m.union=function(){return m.uniq(S(arguments,!0,!0))},m.intersection=function(n){for(var t=[],r=arguments.length,e=0,u=O(n);u>e;e++){var i=n[e];if(!m.contains(t,i)){for(var o=1;r>o&&m.contains(arguments[o],i);o++);o===r&&t.push(i)}}return t},m.difference=function(n){var t=S(arguments,!0,!0,1);return m.filter(n,function(n){return!m.contains(t,n)})},m.zip=function(){return m.unzip(arguments)},m.unzip=function(n){for(var t=n&&m.max(n,O).length||0,r=Array(t),e=0;t>e;e++)r[e]=m.pluck(n,e);return r},m.object=function(n,t){for(var r={},e=0,u=O(n);u>e;e++)t?r[n[e]]=t[e]:r[n[e][0]]=n[e][1];return r},m.findIndex=t(1),m.findLastIndex=t(-1),m.sortedIndex=function(n,t,r,e){r=x(r,e,1);for(var u=r(t),i=0,o=O(n);o>i;){var a=Math.floor((i+o)/2);r(n[a])<u?i=a+1:o=a}return i},m.indexOf=r(1,m.findIndex,m.sortedIndex),m.lastIndexOf=r(-1,m.findLastIndex),m.range=function(n,t,r){null==t&&(t=n||0,n=0),r=r||1;for(var e=Math.max(Math.ceil((t-n)/r),0),u=Array(e),i=0;e>i;i++,n+=r)u[i]=n;return u};var E=function(n,t,r,e,u){if(!(e instanceof t))return n.apply(r,u);var i=j(n.prototype),o=n.apply(i,u);return m.isObject(o)?o:i};m.bind=function(n,t){if(g&&n.bind===g)return g.apply(n,l.call(arguments,1));if(!m.isFunction(n))throw new TypeError("Bind must be called on a function");var r=l.call(arguments,2),e=function(){return E(n,e,t,this,r.concat(l.call(arguments)))};return e},m.partial=function(n){var t=l.call(arguments,1),r=function(){for(var e=0,u=t.length,i=Array(u),o=0;u>o;o++)i[o]=t[o]===m?arguments[e++]:t[o];for(;e<arguments.length;)i.push(arguments[e++]);return E(n,r,this,this,i)};return r},m.bindAll=function(n){var t,r,e=arguments.length;if(1>=e)throw new Error("bindAll must be passed function names");for(t=1;e>t;t++)r=arguments[t],n[r]=m.bind(n[r],n);return n},m.memoize=function(n,t){var r=function(e){var u=r.cache,i=""+(t?t.apply(this,arguments):e);return m.has(u,i)||(u[i]=n.apply(this,arguments)),u[i]};return r.cache={},r},m.delay=function(n,t){var r=l.call(arguments,2);return setTimeout(function(){return n.apply(null,r)},t)},m.defer=m.partial(m.delay,m,1),m.throttle=function(n,t,r){var e,u,i,o=null,a=0;r||(r={});var c=function(){a=r.leading===!1?0:m.now(),o=null,i=n.apply(e,u),o||(e=u=null)};return function(){var f=m.now();a||r.leading!==!1||(a=f);var l=t-(f-a);return e=this,u=arguments,0>=l||l>t?(o&&(clearTimeout(o),o=null),a=f,i=n.apply(e,u),o||(e=u=null)):o||r.trailing===!1||(o=setTimeout(c,l)),i}},m.debounce=function(n,t,r){var e,u,i,o,a,c=function(){var f=m.now()-o;t>f&&f>=0?e=setTimeout(c,t-f):(e=null,r||(a=n.apply(i,u),e||(i=u=null)))};return function(){i=this,u=arguments,o=m.now();var f=r&&!e;return e||(e=setTimeout(c,t)),f&&(a=n.apply(i,u),i=u=null),a}},m.wrap=function(n,t){return m.partial(t,n)},m.negate=function(n){return function(){return!n.apply(this,arguments)}},m.compose=function(){var n=arguments,t=n.length-1;return function(){for(var r=t,e=n[t].apply(this,arguments);r--;)e=n[r].call(this,e);return e}},m.after=function(n,t){return function(){return--n<1?t.apply(this,arguments):void 0}},m.before=function(n,t){var r;return function(){return--n>0&&(r=t.apply(this,arguments)),1>=n&&(t=null),r}},m.once=m.partial(m.before,2);var M=!{toString:null}.propertyIsEnumerable("toString"),I=["valueOf","isPrototypeOf","toString","propertyIsEnumerable","hasOwnProperty","toLocaleString"];m.keys=function(n){if(!m.isObject(n))return[];if(v)return v(n);var t=[];for(var r in n)m.has(n,r)&&t.push(r);return M&&e(n,t),t},m.allKeys=function(n){if(!m.isObject(n))return[];var t=[];for(var r in n)t.push(r);return M&&e(n,t),t},m.values=function(n){for(var t=m.keys(n),r=t.length,e=Array(r),u=0;r>u;u++)e[u]=n[t[u]];return e},m.mapObject=function(n,t,r){t=x(t,r);for(var e,u=m.keys(n),i=u.length,o={},a=0;i>a;a++)e=u[a],o[e]=t(n[e],e,n);return o},m.pairs=function(n){for(var t=m.keys(n),r=t.length,e=Array(r),u=0;r>u;u++)e[u]=[t[u],n[t[u]]];return e},m.invert=function(n){for(var t={},r=m.keys(n),e=0,u=r.length;u>e;e++)t[n[r[e]]]=r[e];return t},m.functions=m.methods=function(n){var t=[];for(var r in n)m.isFunction(n[r])&&t.push(r);return t.sort()},m.extend=_(m.allKeys),m.extendOwn=m.assign=_(m.keys),m.findKey=function(n,t,r){t=x(t,r);for(var e,u=m.keys(n),i=0,o=u.length;o>i;i++)if(e=u[i],t(n[e],e,n))return e},m.pick=function(n,t,r){var e,u,i={},o=n;if(null==o)return i;m.isFunction(t)?(u=m.allKeys(o),e=b(t,r)):(u=S(arguments,!1,!1,1),e=function(n,t,r){return t in r},o=Object(o));for(var a=0,c=u.length;c>a;a++){var f=u[a],l=o[f];e(l,f,o)&&(i[f]=l)}return i},m.omit=function(n,t,r){if(m.isFunction(t))t=m.negate(t);else{var e=m.map(S(arguments,!1,!1,1),String);t=function(n,t){return!m.contains(e,t)}}return m.pick(n,t,r)},m.defaults=_(m.allKeys,!0),m.create=function(n,t){var r=j(n);return t&&m.extendOwn(r,t),r},m.clone=function(n){return m.isObject(n)?m.isArray(n)?n.slice():m.extend({},n):n},m.tap=function(n,t){return t(n),n},m.isMatch=function(n,t){var r=m.keys(t),e=r.length;if(null==n)return!e;for(var u=Object(n),i=0;e>i;i++){var o=r[i];if(t[o]!==u[o]||!(o in u))return!1}return!0};var N=function(n,t,r,e){if(n===t)return 0!==n||1/n===1/t;if(null==n||null==t)return n===t;n instanceof m&&(n=n._wrapped),t instanceof m&&(t=t._wrapped);var u=s.call(n);if(u!==s.call(t))return!1;switch(u){case"[object RegExp]":case"[object String]":return""+n==""+t;case"[object Number]":return+n!==+n?+t!==+t:0===+n?1/+n===1/t:+n===+t;case"[object Date]":case"[object Boolean]":return+n===+t}var i="[object Array]"===u;if(!i){if("object"!=typeof n||"object"!=typeof t)return!1;var o=n.constructor,a=t.constructor;if(o!==a&&!(m.isFunction(o)&&o instanceof o&&m.isFunction(a)&&a instanceof a)&&"constructor"in n&&"constructor"in t)return!1}r=r||[],e=e||[];for(var c=r.length;c--;)if(r[c]===n)return e[c]===t;if(r.push(n),e.push(t),i){if(c=n.length,c!==t.length)return!1;for(;c--;)if(!N(n[c],t[c],r,e))return!1}else{var f,l=m.keys(n);if(c=l.length,m.keys(t).length!==c)return!1;for(;c--;)if(f=l[c],!m.has(t,f)||!N(n[f],t[f],r,e))return!1}return r.pop(),e.pop(),!0};m.isEqual=function(n,t){return N(n,t)},m.isEmpty=function(n){return null==n?!0:k(n)&&(m.isArray(n)||m.isString(n)||m.isArguments(n))?0===n.length:0===m.keys(n).length},m.isElement=function(n){return!(!n||1!==n.nodeType)},m.isArray=h||function(n){return"[object Array]"===s.call(n)},m.isObject=function(n){var t=typeof n;return"function"===t||"object"===t&&!!n},m.each(["Arguments","Function","String","Number","Date","RegExp","Error"],function(n){m["is"+n]=function(t){return s.call(t)==="[object "+n+"]"}}),m.isArguments(arguments)||(m.isArguments=function(n){return m.has(n,"callee")}),"function"!=typeof/./&&"object"!=typeof Int8Array&&(m.isFunction=function(n){return"function"==typeof n||!1}),m.isFinite=function(n){return isFinite(n)&&!isNaN(parseFloat(n))},m.isNaN=function(n){return m.isNumber(n)&&n!==+n},m.isBoolean=function(n){return n===!0||n===!1||"[object Boolean]"===s.call(n)},m.isNull=function(n){return null===n},m.isUndefined=function(n){return n===void 0},m.has=function(n,t){return null!=n&&p.call(n,t)},m.noConflict=function(){return u._=i,this},m.identity=function(n){return n},m.constant=function(n){return function(){return n}},m.noop=function(){},m.property=w,m.propertyOf=function(n){return null==n?function(){}:function(t){return n[t]}},m.matcher=m.matches=function(n){return n=m.extendOwn({},n),function(t){return m.isMatch(t,n)}},m.times=function(n,t,r){var e=Array(Math.max(0,n));t=b(t,r,1);for(var u=0;n>u;u++)e[u]=t(u);return e},m.random=function(n,t){return null==t&&(t=n,n=0),n+Math.floor(Math.random()*(t-n+1))},m.now=Date.now||function(){return(new Date).getTime()};var B={"&":"&amp;","<":"&lt;",">":"&gt;",'"':"&quot;","'":"&#x27;","`":"&#x60;"},T=m.invert(B),R=function(n){var t=function(t){return n[t]},r="(?:"+m.keys(n).join("|")+")",e=RegExp(r),u=RegExp(r,"g");return function(n){return n=null==n?"":""+n,e.test(n)?n.replace(u,t):n}};m.escape=R(B),m.unescape=R(T),m.result=function(n,t,r){var e=null==n?void 0:n[t];return e===void 0&&(e=r),m.isFunction(e)?e.call(n):e};var q=0;m.uniqueId=function(n){var t=++q+"";return n?n+t:t},m.templateSettings={evaluate:/<%([\s\S]+?)%>/g,interpolate:/<%=([\s\S]+?)%>/g,escape:/<%-([\s\S]+?)%>/g};var K=/(.)^/,z={"'":"'","\\":"\\","\r":"r","\n":"n","\u2028":"u2028","\u2029":"u2029"},D=/\\|'|\r|\n|\u2028|\u2029/g,L=function(n){return"\\"+z[n]};m.template=function(n,t,r){!t&&r&&(t=r),t=m.defaults({},t,m.templateSettings);var e=RegExp([(t.escape||K).source,(t.interpolate||K).source,(t.evaluate||K).source].join("|")+"|$","g"),u=0,i="__p+='";n.replace(e,function(t,r,e,o,a){return i+=n.slice(u,a).replace(D,L),u=a+t.length,r?i+="'+\n((__t=("+r+"))==null?'':_.escape(__t))+\n'":e?i+="'+\n((__t=("+e+"))==null?'':__t)+\n'":o&&(i+="';\n"+o+"\n__p+='"),t}),i+="';\n",t.variable||(i="with(obj||{}){\n"+i+"}\n"),i="var __t,__p='',__j=Array.prototype.join,"+"print=function(){__p+=__j.call(arguments,'');};\n"+i+"return __p;\n";try{var o=new Function(t.variable||"obj","_",i)}catch(a){throw a.source=i,a}var c=function(n){return o.call(this,n,m)},f=t.variable||"obj";return c.source="function("+f+"){\n"+i+"}",c},m.chain=function(n){var t=m(n);return t._chain=!0,t};var P=function(n,t){return n._chain?m(t).chain():t};m.mixin=function(n){m.each(m.functions(n),function(t){var r=m[t]=n[t];m.prototype[t]=function(){var n=[this._wrapped];return f.apply(n,arguments),P(this,r.apply(m,n))}})},m.mixin(m),m.each(["pop","push","reverse","shift","sort","splice","unshift"],function(n){var t=o[n];m.prototype[n]=function(){var r=this._wrapped;return t.apply(r,arguments),"shift"!==n&&"splice"!==n||0!==r.length||delete r[0],P(this,r)}}),m.each(["concat","join","slice"],function(n){var t=o[n];m.prototype[n]=function(){return P(this,t.apply(this._wrapped,arguments))}}),m.prototype.value=function(){return this._wrapped},m.prototype.valueOf=m.prototype.toJSON=m.prototype.value,m.prototype.toString=function(){return""+this._wrapped},"function"==typeof define&&define.amd&&define("underscore",[],function(){return m})}).call(this);;
(function ($) {

Drupal.facetapi = (Drupal.facetapi) ? Drupal.facetapi : {};

/**
 * Overides Facet API's behavior to keep facets open when they're
 * specified in the URL fragment.
 *
 * @see facetapi.js
 * @see vivodashboard_core_preprocess_facetapi_link_inactive()
 */
Drupal.facetapi.applyLimit = function(settings) {

    var currPage = $(location).attr('href');
    if(currPage.indexOf("/publications") != -1){
        var linksToMain = $('a[href="/publications"]');
        linksToMain.addClass("active");
    }

  if (settings.limit > 0 && !$('ul#' + settings.id).hasClass('facetapi-processed')) {
    // Only process this code once per page load.
    $('ul#' + settings.id).addClass('facetapi-processed');

    // Ensures our limit is zero-based, hides facets over the limit.
    var limit = settings.limit - 1;

    var open = false;
    if (settings.facetName && window.location.hash && "#" + settings.facetName == window.location.hash) {
      open = true;
    }

    if (!open) {
      $('ul#' + settings.id).find('li:gt(' + limit + ')').hide();
    }

    var linkText = (open) ? Drupal.t('Show less') : Drupal.t('Show more');

    // Adds "Show more" / "Show fewer" links as appropriate.
    $('ul#' + settings.id).filter(function() {
      return $(this).find('li').length > settings.limit;
    }).each(function() {
      $('<a href="#" class="facetapi-limit-link"></a>').text(linkText).click(function() {
        if ($(this).prev().find('li:hidden').length > 0) {
          $(this).prev().find('li:gt(' + limit + ')').slideDown();
          $(this).addClass('open').text(Drupal.t('Show fewer'));
        }
        else {
          $(this).prev().find('li:gt(' + limit + ')').slideUp();
          $(this).removeClass('open').text(Drupal.t('Show more'));
        }
        return false;
      }).insertAfter($(this));
    });
  }
}

})(jQuery);
;
function calloutPreviousPage(index) {
    jQuery('.metadataContainer').hide();
    jQuery('#article_metadata_' + (index - 1)).show();
}

function calloutNextPage(index) {
    jQuery('.metadataContainer').hide();
    jQuery('#article_metadata_' + (index + 1)).show();
}

jQuery(document).on('mouseover', '.qtip-citation-btn', function() {
    jQuery('.qtip-citation-btn').qtip({
     position: {
            my: 'left center',
            at: 'right center'
        },
        style: {
            classes: 'qtip-light qtip-shadow popupContainer'
        },
        show: {
            event: 'click',
        },
        hide: {
            event: 'unfocus'
        }
    })
});

jQuery(document).on('mouseover', '.qtip-citation-author', function() {
    jQuery(this).qtip({
        content: {
            text: function(event, api) {
                console.log(api.elements.target.attr('data-cwid'));
                jQuery.ajax({
                    url: '/publication_profile_by_cwid/'+api.elements.target.attr('data-cwid') // Use href attribute as URL
                })
                .then(function(content) {
                    // Set the tooltip content upon successful retrieval
                    api.set('content.text', content);
                }, function(xhr, status, error) {
                    // Upon failure... set the tooltip content to error
                    api.set('content.text', status + ': ' + error);
                });

                return 'Loading...'; // Set some initial text
            },
            button: true
        },
        position: {
            my: 'center', at: 'center',
            target: jQuery(window)
        },
        style: {
            classes: 'qtip-light qtip-shadow popupContainer popupAuthorContainer'
        },
        show: {
            event: 'click',
            modal: {
                on: true
            }
        },
        hide: {
            event: 'unfocus'
        }
    });
});

(function ($) {

    Drupal.behaviors.citations = { attach: function (select, settings) {

        var width = 700;
        var height = 640;
        var graphLeftMargin = 50;
        var graphTopMargin = 50;
        var legendWidth = 670 ;
        var legendHeight = 250;

        var blockWidth = 200;
        var blockHeight = 50;
        var blockTopMargin = 2;
        var blockBottomMargin = 3;
        var axisStart = 39;
        var axisWidth = 7;

        /**
         * Preferred tile dimensions. These will be scaled down if it turns out that
         * there's not enough space available (see below).
         */
        var tileMargin = 2;
        var tileWidth = 16;
        var tileHeight = 14;

        /**
         * The 'blockWidth' includes the space for the axis and label. When we substract
         * the space required for those, we get the space available for the tiles. If
         * this space is not wide enough for the largest decile in our data, we need to
         * scale down the tiles from their preferred dimensions.
         */
        var tileScale = 1;

        /* The entire unprocessed data-set */
        var unprocessedData;

        var articlesPerSquare = 1;

        /* A global variable to check if articles less than 10 in any time frame. */
        var showMsg = 0;

        var linksToMain = jQuery('a[href^="/citations/main"]');
        linksToMain.addClass("active");

        var linksToPictograph = jQuery('a[href^="/citations/pictograph"]');
        linksToPictograph.addClass("active");

        $( "#popupContainer" ).click(function() {
            $( "#popupContainer").popup();
        });

        /////
        /*$('.notification-close').click(function() {
            $('.notification').hide();
            var d = new Date();
            d.setTime(d.getTime() + (10000 * 365 * 24 * 60 * 60));
            var expires = "expires="+ d.toGMTString();
            document.cookie = 'Drupal.visitor.citation_notification=1; '+expires +';path=/';
        });*/
        //////

        refreshGraph()

        /**
         * Refreshes the impact graph.
         */
        function refreshGraph() {

            var chartData = Drupal.settings.citations.violinData;

            articlesPerSquare = Drupal.settings.citations.articlesPerSquare;

            unprocessedData = chartData;

            var timePeriods = generateTimePeriods();
            var dataSet = [
                [
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    []
                ],
                [
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    []
                ],
                [
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    [],
                    []
                ]
            ];

            var articles = _.sortBy(deduplicate(chartData), function (d) {
                return isReview(d);
            });

            for (var i = 0; i < chartData.length; i++) {
                var article = chartData[i];
                if (typeof article !== 'undefined') {
                    var dateString = article.cover_date;
                    var year = parseInt(dateString.split("-")[0]);
                    for (var j = 0; j < timePeriods.length; j++) {
                        if (timePeriods[j][0] <= year && timePeriods[j][1] >= year) {
                            var percentileRank = parseInt(article.percentile_rank);
                            var percentileIndex = Math.floor((percentileRank / 10) - 0.1);
                            dataSet[j][percentileIndex].push(article);
                            break;
                        }
                    }
                }
            }

            // Determine if we need to scale down the tiles to fit the available space.
            // See declaration of 'tileScale' for more details.

            var maxBlockWidth =
                _.reduce(
                    _.flatten(dataSet, true),
                    function(memo, value) {
                        return Math.max(memo, calculateBlockWidth(value));
                    },
                    0
                );

            var availableSpace = blockWidth - axisStart - axisWidth;
            if (maxBlockWidth > availableSpace) {
                tileScale = availableSpace / maxBlockWidth;
            } else {
                tileScale = 1;
            }

            drawGraph(dataSet);
        }

        /**
         * Draws a new graph by using the provided data-set.
         */
        function drawGraph(dataSet) {
            d3.select("#svgContainer").selectAll("*").remove();
            var svg =
                d3.select("#svgContainer")
                    .append("svg")
                    .attr("width", width)
                    .attr("height", height);

            svg.append("text")
                .attr("class", "label percentileLabel")
                .attr("transform", "translate(15," + (10 * (blockHeight + blockBottomMargin)) / 2 + ") rotate(-90)")
                .style("text-anchor", "middle")
                .text("Percentile rank of times cited");

            svg.append("text")
                .attr("class", "label percentileLabel")
                .attr("transform", "translate(35," + (10 * (blockHeight + blockBottomMargin)) / 2 + ") rotate(-90)")
                .style("text-anchor", "middle")
                .text("better \u2192");

            var timePeriodLimits = generateTimePeriods();
            dataSet.forEach(function (timePeriodData, i) {

                var startX = i * (blockWidth + 10) + graphLeftMargin;
                var articleCount = 0;
                timePeriodData.forEach(function (d) { articleCount += d.length; });

                if(articleCount > 0 && articleCount < 10){
                    showMsg = 1;
                }


                var percentileMedian =
                    Math.round(
                        d3.median(
                            _.map(
                                _.flatten(timePeriodData),
                                function(d) { return d.percentile_rank; }
                            )
                        )
                    );

                // Show label for the time-frame
                var timePeriodLabel = timePeriodLimits[i][0] + "-" + timePeriodLimits[i][1];
                svg.append("text")
                    .attr("class", "label timeFrameLabel")
                    .attr("transform", "translate(" + (startX + 52) + ",20)")
                    .text(timePeriodLabel);

                svg.append("text")
                    .attr("class", "label articleCount")
                    .attr("transform", "translate(" + (startX + 52) + ",40)")
                    .text(articleCount + " total articles");

                // Draw percentiles for this time-frame
                timePeriodData.forEach(function (block, j) {
                    var startY = (j * (blockHeight + blockBottomMargin) + graphTopMargin);
                    var axisGroup = svg.append("g").attr("transform", "translate(" + startX + "," + startY + ")");
                    var blockGroup = svg.append("g").attr("transform", "translate(" + startX + "," + startY + ")");
                    var upperBound = ((j + 1) * 10);
                    var lowerBound = upperBound - 9;
                    drawBlock(axisGroup, blockGroup, block, lowerBound, upperBound, percentileMedian, i, blockWidth, blockHeight);
                });
            });

            drawLegend();
        }

        /**
         * Draws a new decile block based on provided the data and dimensions.
         */
        function drawBlock(axisGroup, blockGroup, articles, lowerBound, upperBound, percentileMedian, timePeriodIndex, width, height) {

            axisGroup.append("path")
                .attr("class", "axis")
                .attr("d", "M " + axisStart + " " + blockTopMargin + " " +
                    "L " + (axisStart + axisWidth) + " " + blockTopMargin + " " +
                    "L " + (axisStart + axisWidth) + " " + (height - blockTopMargin) + " " +
                    "L " + axisStart + " " + (height - blockTopMargin));

            // Show a median marker if the percentile median falls into this decile;
            // otherwise show axis label for the decile (there's not enough space for both)
            if (lowerBound <= percentileMedian && upperBound >= percentileMedian) {
                drawPercentileMarker(axisGroup, percentileMedian, (((percentileMedian - lowerBound) / 10) * height) + 3, timePeriodIndex);
            } else {
                axisGroup.append("text")
                    .attr("class", "label axisLabel")
                    .attr("x", 2)
                    .attr("y", height / 2)
                    .text(lowerBound + "-" + upperBound);
            }

            // Split articles into chunks based on the articlesPerSquare parameter. If
            // the value is higher than 1, each tile will represent multiple articles.

            // Note that reviews will still always go to separate chunks. Therefore, we
            // first partition the articles and then chunk the two partitions independently.
            // As a final step, we then merge the two partitions back into a singe array.

            // var partitionedArticles = articles.partition(function(article) { return !isReview(article); });
            // var partitionedArticles = partition(articles, function(article) { return !isReview(article); });
            // var partitionedAndChunkedArticles = [partitionedArticles[0].chunk(articlesPerSquare), partitionedArticles[1].chunk(articlesPerSquare)];
            // var partitionedAndChunkedArticles = [chunk(partitionedArticles[0], articlesPerSquare), chunk(partitionedArticles[1], articlesPerSquare)];


            var partitionedArticles = partition(articles, function(article) { return !isReview(article); });
            var researchArticles = _.sortBy(partitionedArticles[0], function(article) { return Number(article.percentile_rank); })
            var reviews = _.sortBy(partitionedArticles[1], function(article) { return Number(article.percentile_rank); })
            var partitionedAndChunkedArticles = [chunk(researchArticles, articlesPerSquare), chunk(reviews, articlesPerSquare)];

            var chunkedArticles = _.flatten(partitionedAndChunkedArticles, true);

            // Calculate the X-coordinate for the first tile
            var tileStart = axisStart + axisWidth + 7;

            // Create a group for the tiles so that they can be scaled if necessary
            var tileGroup =
                blockGroup.append("g")
                    .attr("class", "tileGroup")
                    .attr("transform", "translate(" + tileStart + " 0)");

            // Finally, draw the tiles.
            var tiles = tileGroup.selectAll(".tile")
                .data(chunkedArticles)
                .enter()
                .append("rect")
                .attr("id", function(d) { return "article_" + d[0].publication_nid; })
                .attr("class", function (d) { return isReviewArray(d) ? "tile reviewTile" : "tile researchArticleTile";})
                .attr("x", function(d,i) { return (Math.ceil((i + 1) / 3) - 1) * (tileWidth + tileMargin);})
                .attr("y", function(d,i) { return blockTopMargin + (((i + 1) % 3 == 0) ? 2 : (((i + 1) % 3) - 1)) * (tileHeight + tileMargin);})
                .attr("width", function(d) { return calculateTileWidth(d); })
                .attr("height", tileHeight - tileMargin)
                .on("mouseover", function(d) { d3.select(this).style("opacity", 0.7); showArticleMessage('#article_' + d[0].publication_nid); })
                .on("mouseout", function(d) { d3.select(this).style("opacity", 1); })
                .on("click", function(d) { showArticleCallout('#article_' + d[0].publication_nid, d, articles); })

            tileGroup.attr("transform", "translate(" + tileStart + " 0) scale(" + tileScale + " 1)");
        }

        /**
         * Calculates the tile width. If the article count is less than the value of
         * articlesPerSquare, we need to scale the tile size accordingly.
         */
        function calculateTileWidth(chunkedArticles) {
            if (chunkedArticles.length < articlesPerSquare) {
                // -1 in the end accounts for the fact that current SVG implementations offer
                // very little control over the stroke location. Width of the stoke is always
                // fixed and partially outside the shape (thus increasing the outer dimensions).
                return (chunkedArticles.length / articlesPerSquare) * (tileWidth - tileMargin) - 1;
            } else {
                return tileWidth - tileMargin;
            }
        }

        /**
         * Calculates the block width when using preferred tile dimensions.
         */
        function calculateBlockWidth(articles) {
            return Math.ceil(Math.ceil(articles.length / articlesPerSquare) / 3) * (tileWidth + tileMargin);
        }

        /**
         * Draws the percentile marker.
         */
        function drawPercentileMarker(svg, percentile, position, timePeriodIndex) {

            var pointX = 40;
            var pointY = position;
            var markerHeight = 20;
            var markerGroup =
                svg.append("g")
                    .attr("id", function(d) { return "median_" + timePeriodIndex; })
                    .on("mouseover", function(d) { showMedianCallout(percentile, timePeriodIndex); });

            markerGroup.append("path")
                .attr("class", "medianMarker")
                .attr("d", "M " + pointX + " " + pointY + " " +
                    "L " + (pointX - markerHeight * 0.66) + " " + (pointY - markerHeight / 2) + " " +
                    "L " + (pointX - markerHeight * 1.66) + " " + (pointY - markerHeight / 2) + " " +
                    "L " + (pointX - markerHeight * 1.66) + " " + (pointY + markerHeight / 2) + " " +
                    "L " + (pointX - markerHeight * 0.66) + " " + (pointY + markerHeight / 2) + " " +
                    "L " + pointX + " " + pointY);

            markerGroup.append("text")
                .attr("class", "label medianMarkerLabel")
                .attr("x", pointX - markerHeight * 1.16)
                .attr("y", pointY)
                .style("pointer-events", "none")
                .append("tspan")
                .attr("dy", "3pt") /* An ugly hack because IE does not respect alignment-baseline: middle */
                .text(percentile);

            return markerGroup;
        }

        function drawLegend() {
            d3.select("#svgLegendContainer").selectAll("*").remove();
            var svg =
                d3.select("#svgLegendContainer")
                    .append("svg")
                    .attr("width", legendWidth)
                    .attr("height", legendHeight);

            var yLevel = 20;
            var marker = drawPercentileMarker(svg, "X", yLevel);
            marker.attr("transform", "scale(0.6,0.6)");

            svg.append("text")
                .attr("class", "label legendLabel")
                .attr("x", 35)
                .attr("y", yLevel * 0.7)
                .text("Median percentile rank");

            svg.append("rect")
                .attr("class", "researchArticleTile")
                .attr("x", 4)
                .attr("y", yLevel + (tileHeight + tileMargin) / 2)
                .attr("width", tileWidth - tileMargin)
                .attr("height", tileHeight - tileMargin);

            svg.append("text")
                .attr("class", "label legendLabel")
                .attr("x", 35)
                .attr("y", yLevel + tileHeight + 2)
                .text("Academic article");

            svg.append("rect")
                .attr("class", "reviewTile")
                .attr("x", 4)
                .attr("y", 52)
                .attr("width", tileWidth - tileMargin)
                .attr("height", tileHeight - tileMargin);

            svg.append("text")
                .attr("class", "label legendLabel")
                .attr("x", 35)
                .attr("y", 60)
                .text("Review");

            /*svg.append("text")
                .attr("class", "label legendLabel")
                .attr("x", 4)
                .attr("y", 85)
                .text("This chart shows ONLY those articles with citation count data available.");*/

            if(showMsg == 1){
                svg.append("text")
                    .attr("class", "label legendLabel")
                    .attr("x", 4)
                    .attr("y", 105)
                    .text("Note that there are fewer than 10 articles in at least one time period. Please use caution when");
                svg.append("text")
                    .attr("class", "label legendLabel")
                    .attr("x", 4)
                    .attr("y", 125)
                    .text("drawing conclusions about the percentile rank of times cited for this researcher\'s articles.");

            }

        }

        /**
         * Generates the time periods to use. In the literature it is recommended that
         * the two most recent years are excluded from the analysis.
         */
        function generateTimePeriods() {
            var currentYear = new Date().getFullYear();
            return [[currentYear - 12, currentYear - 9],
                [currentYear - 8, currentYear - 6],
                [currentYear - 5, currentYear - 3]];
        }

        /**
         * Checks if the given article is a review.
         *
         * @param article The article to check
         */
        function isReview(article) {
            var isReview = false;
            if (article.pubtype !== undefined && article.pubtype !== null) {
                article.pubtype.split('|').forEach(function(d) {
                    if (d == "Review") isReview = true;
                });
            }
            return isReview;
        }

        /**
         * Checks if the given article array consists of reviews.
         *
         * @param articles The articles
         */
        function isReviewArray(articles) {
            return articles.length > 0 ? isReview(articles[0]) : false;
        }

        /**
         * In the data-set, one article will have one row per category. To avoid double
         * counting, here we deduplicate the list and ensure that we always choose the
         * category with highest percentile rank and ignore the other categories.
         *
         * @param articles a list of articles to deduplicate
         */
        function deduplicate(articles) {
            var deduplicated = [];
            articles.forEach(function(d) {
                var i = _.findIndex(deduplicated, function(e) { return e.pmid == d.pmid; }); // O(n^2)
                if (i > -1) {
                    var existingRank = parseInt(deduplicated[i].percentile_rank);
                    var currentRank = parseInt(d.percentile_rank);
                    if (currentRank > existingRank) {
                        deduplicated[i] = d;
                    }
                } else {
                    deduplicated.push(d);
                }
            });
            return deduplicated;
        }


        /**
         * Splits the array into chunks of specified size.
         *
         * @param chunkSize the size of the chunks
         */
        function chunk(data, chunkSize) {
            var array = data;
            return [].concat.apply([],
                array.map(function(elem, i) {
                    return i % chunkSize ? [] : [array.slice(i, i + chunkSize)];
                })
            );
        }

        /**
         * Partitions the array based on a discriminator function.
         *
         * @param discriminator the discriminator function to use
         */
        function partition(data, discriminator) {
            var matched = [],
                unmatched = [],
                i = 0,
                j = data.length;

            for (; i < j; i++) {
                (discriminator.call(data, data[i], i) ? matched : unmatched).push(data[i]);
            }
            return [matched, unmatched];
        }

        /**
         * Shows a callout next to the specified median marker.
         *
         * @param marker the median marker
         */
        function showMedianCallout(percentile, timePeriodIndex) {
            $('div.qtip:visible').qtip('hide');
            $("#median_" + timePeriodIndex).qtip({
                content: {
                    text: function() {
                        var timePeriodLimits = generateTimePeriods();
                        var timePeriodLabel = timePeriodLimits[timePeriodIndex][0] + "-" + timePeriodLimits[timePeriodIndex][1];
                        
                        return "For "+timePeriodLabel+" the median percentile rank of citations received "+
                        "for each article, adjusted for year, article type, and field of publication.";                        
                    }
                },
                position: {
                    my: 'left center',
                    at: 'right center'
                },
                style: {
                    classes: 'qtip-light qtip-shadow popupContainer'
                },
                show: {
                    event: 'click',
                    ready: true
                }
            });
        }

        /**
         * Shows a callout next to the specified tile containing metadata
         * about the specified articles (there can be many if articlesPerSquare > 1).
         *
         * @param tile the tile representing the articles
         * @param articles the articles
         */
        function showArticleCallout(tile, articles) {
            $(tile).qtip({
                content: {
                    text: function() {
                        return createMetadata(articles);
                    }
                },
                position: {
                    viewport: $(window),
                    my: 'left center',
                    at: 'right center'
                },
                style: {
                    classes: 'qtip-light qtip-shadow popupContainer'
                },
                show: {
                    event: 'click',
                    ready: true
                },
                hide: {
                    event: 'unfocus'
                }
            });
        }

        // Citation tile hover
        function showArticleMessage(tile) {
            $(tile).qtip({
                content: {
                    text: 'Click to view details.'
                }, 
                position: {
                    my: 'left center',
                    at: 'right center'
                },
                style: {
                    classes: 'qtip-light qtip-shadow'
                },
                show: {
                    event: 'mouseenter',
                    ready: true
                },
                hide: {
                    event: 'mouseleave'
                }
            });
        } 

        // Capitalize Text functions
        function capitalizeTxt(txt) {
          return txt.charAt(0).toUpperCase() + txt.slice(1);
        }

        /**
         * Creates a summary of a chunk of articles (shown on the popup).
         *
         * @param articles the articles
         */
        function createMetadata(articles) {

            $('.metadataContainer').remove(); // Needed to avoid flickering.

            var result = "";
            articles.forEach(function (article, i) {

                // The title of the article is formatted as follows:
                // Authors. Title. Journal. Year Month;Volume(Issue):Pages.

                var year = parseInt(article.cover_date.split("-")[0]);
                var month = parseInt(article.cover_date.split("-")[1]);

                if (i == 0) {
                    result += '<div class="metadataContainer" id="article_metadata_' + i + '">';
                } else {
                    result += '<div class="metadataContainer" id="article_metadata_' + i + '" style="display: none;">';
                }

                // The inner container has a fixed minimum height. This way the navigation
                // links below will stay in fixed position when the users clicks through
                // the articles. Otherwise they would jump around depending on the height
                // of the content.

                result += '<div class="innerMetadataContainer">';

                var summary = createCitationSummary(article);
                if (summary !== "" && summary !== null) {
                    result += summary; // + "<br /><br />" ;
                }

                if (article.title !== "" && article.title !== null) {
                    result += "<strong>Title:</strong> " + article.title + ".<br>";
                }

                var authors = "";
                if (article.authors !== "" && article.authors !== null) {
                    authors = createAuthorMetadata(article);
                }
                if (authors !== "" && authors !== null) {
                    result +=  "<strong>Author(s):</strong> " + authors;
                    // result +=  "<strong>" + authors + "</strong>. ";
                }

                if (article.author_rank !== "" && article.author_rank !== null && article.author_rank !== undefined) {
                    result += "<br><strong>Author Rank:</strong> "+capitalizeTxt(article.author_rank);
                }

                if (article.pubtype !== "" && article.pubtype !== null && article.pubtype !== undefined) {
                    result += "<br><strong>Type:</strong> "+article.pubtype+"<br>";
                }

                if (article.authors_citation_popup !== "" && article.authors_citation_popup !== null && article.authors_citation_popup !== undefined) {
                    result += '<hr><div class=\"field-citations-qtip\"><div class=\"qtip-citation-btn\" title="';
                    result += article.authors_citation_popup +". ";
                    if (article.title !== "" && article.title !== null && article.title !== undefined) {
                        result += article.title + ". " ;
                    }
                    if (article.publication_name !== "" && article.publication_name !== null && article.publication_name !== undefined) {
                        result += article.publication_name + ". " ;
                    }
                    if (year !== "" && year !== null && year !== NaN && year !== undefined) {
                        result += year + " ";
                    }
                    if (article.volume !== "" && article.volume !== null && article.volume !== undefined) {
                        result += article.volume;
                    }
                    if (article.issue !== "" && article.issue !== null && article.issue !== undefined) {
                        result +=  article.issue;
                    }
                    if (article.page_start !== "" && article.page_start !== null && article.page_start !== undefined) {
                        result +=  ":" + article.page_start + ".";
                    }
                    if (article.pmid !== "" && article.pmid !== null && article.pmid !== undefined) {
                        result +=  " PMID: " + article.pmid + ".";
                    } 
                     if (article.pmcid !== "" && article.pmcid !== null && article.pmcid !== undefined) {
                        result +=  " PMCID: " + article.pmcid + ".";
                    } 


                    result +='">Citation <span>+</span></div></div>';
                }

                /*if (article.title !== "" && article.title !== null) {
                    result += article.title + ". " ;
                }

                if (article.publication_name !== "" && article.publication_name !== null) {
                    result += "<i>" + article.publication_name + "</i>. " ;
                }

                if (year !== "" && year !== null && year !== NaN) {
                    result += year + " ";
                }

                if (month !== "" && month !== null && month !== NaN) {
                    result += month + "; ";
                }

                if (article.volume !== "" && article.volume !== null) {
                    result += article.volume ;
                }

                if (article.issue !== "" && article.issue !== null) {
                    result += "(" + article.issue + ")" ;
                }

                if (article.pages !== "" && article.pages !== null) {
                    result +=  ":" + article.pages + ".<br/><br />"  ;
                } else {
                    result += ".<br/><br />"  ;
                }*/

                // var summary = createCitationSummary(article);
                // if (summary !== "" && summary !== null) {
                //     result += summary + "<br /><br />" ;
                // }
                result += "</div>"; // innerMetaDataContainer

                if (article.scopus_doc_id !== "" && article.scopus_doc_id !== null) {
                    // result += "<a href='http://vivo.med.cornell.edu/display/pubid" + article.scopus_doc_id + "'>View details</a>";
                }

                if (articlesPerSquare != 1) {
                    result += createPagination(article, i, articles.length);
                }

                result += "</div>";
            });

            return result;
        }

        /**
         * Creates the author segment of the article summary. If there are more than five
         * authors, we want to format the segment as follows:
         *
         * North BJ, Rosenberg MA, Jeganathan KB, (...), Rosenzweig A, Sinclair DA
         *
         * @param article the article
         */
        function createAuthorMetadata(article) {
          var authors = article.authors.split('|');
          var separator = ', ';
          return authors.join(separator);
        }

        /**
         * Creates the citation summary segment of the article summary. We want to
         * format the segment as follows;
         *
         * Times cited: 22
         * Category/rank
         * Cancer (8th), Cell Biology (14th), Biochemistry (18th)
         *
         * @param article the article
         */
        function createCitationSummary(article) {
            var articles =
                _.map(
                    // Sorts categories by the percentile rank
                    _.sortBy(
                        // Retrieves all the categories the article appears in
                        _.filter(unprocessedData, function(d) {return d.scopus_doc_id == article.scopus_doc_id;}),
                        'percentile_rank'
                    ),
                    function(d) {

                        if (d.category !== undefined && d.category !== "" && d.category !== null ) {
                            //var category = sanitizeCategory(d.category);
                            return  '<div class="field-citations-impact"><span>'+d.percentile_rank + ordinalIndicator(d.percentile_rank) + '</span> <strong>percentile</strong> (better than '+(100 - d.percentile_rank)+'%) </div><br><strong>Benchmarked Categories:</strong> ' + d.category;
                            // return  d.percentile_rank + ordinalIndicator(d.percentile_rank) + " percentile for " + d.category;
                        }else {
                            return  '<div class="field-citations-impact"><span>'+d.percentile_rank + ordinalIndicator(d.percentile_rank) + '</span> <strong>percentile</strong> (better than '+(100 - d.percentile_rank)+'%)' +'</div>';
                            // return  d.percentile_rank + ordinalIndicator(d.percentile_rank) + " percentile";
                        }

                    }
                );

            // var citeString = "Times cited - " + article.citation_count + "<br />";
            // citeString += "Rank - " + articles.join('; ');

            // var citeString = '<div class="field-citations"><span>'+articles.join('; ')+'</span></div>';
            var citeString = articles.join('; ') + '<br>';

            if (article.scopus_doc_id !== "" && article.scopus_doc_id !== null) {
                citeString += '<strong>Times cited:</strong> <a href="http://www.scopus.com/inward/record.url?partnerID=HzOxMe3b&scp='+article.scopus_doc_id+'" target="_blank">' + article.citation_count + '</a><br /><hr>';
            } else {
                citeString += "<strong>Times cited:</strong> " + article.citation_count + "<br /><hr>";
            }

            // return "Times cited - " + article.citation_count + "<br />" + "Rank - " + articles.join(', ');

            return citeString;
        }

        /**
         * Creates a pagination links for the article.
         *
         * @param article the article
         * @param index the index of the article
         * @param count the total number of articles shown in this callout
         */
        function createPagination(article, index, count) {

            var result = '<span class="paginationContainer">';

            if (index == 0) {
                result += '<i class="fa fa-arrow-left paginationDisabled"></i>';
            } else {
                result += '<a onclick="calloutPreviousPage(' + index + ');"><i class="fa fa-arrow-left paginationEnabled"></i></a>';
            }

            result += '&nbsp;';
            result += isReview(article) ? 'Review' : 'Article';
            result += '&nbsp;' + (index + 1) + ' of ' + count + '&nbsp;';

            if (index == count - 1) {
                result += '<i class="fa fa-arrow-right paginationDisabled"></i>';
            } else {
                result += '<a onclick="calloutNextPage(' + index + ');"><i class="fa fa-arrow-right paginationEnabled"></i></a>';
            }

            result += '</span>';
            return result;
        }



        /**
         * Capitalizes the specified value. For example:
         *
         * BIOCHEMISTRY & MOLECULAR BIOLOGY
         *
         * becomes:
         *
         * Biochemistry & Molecular Biology
         *
         * @param value the value to capitalize
         */
        function sanitizeCategory(value) {

            return _.map(
                value.split(' '),
                /*function(d) { return d.charAt(0).toUpperCase() + d.slice(1).toLowerCase(); }).join(' '); */
                function(d) { return d.charAt(0).toUpperCase() + d.slice(1); }).join(' ');//.replace(/,/g,'; ');
        }

        /**
         * Determines the ordinal indicator to use for the value.
         *
         * @param {int} value The value
         */
        function ordinalIndicator(value) {
            var indicator;
            var modulo = value % 10;
            switch (modulo) {
                case 1:
                    indicator = (value != 11 ? "st" : "th");
                    break;
                case 2:
                    indicator = (value != 12 ? "nd" : "th");
                    break;
                case 3:
                    indicator = (value != 13 ? "rd" : "th")
                    break;
                default:
                    indicator = "th";
            }
            return indicator;
        }


    } }
})(jQuery);;
