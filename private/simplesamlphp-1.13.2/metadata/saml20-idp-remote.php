<?php

//Production Metadata
$metadata['https://login.weill.cornell.edu/idp'] = array (
    'entityid' => 'https://login.weill.cornell.edu/idp',
    'description' =>
        array (
            'en' => 'Weill Cornell Medicine',
        ),
    'OrganizationName' =>
        array (
            'en' => 'Weill Cornell Medicine',
        ),
    'name' =>
        array (
            'en' => 'Weill Cornell Medicine',
        ),
    'OrganizationDisplayName' =>
        array (
            'en' => 'Weill Cornell Medicine',
        ),
    'url' =>
        array (
            'en' => 'http://weill.cornell.edu/',
        ),
    'OrganizationURL' =>
        array (
            'en' => 'http://weill.cornell.edu/',
        ),
    'contacts' =>
        array (
            0 =>
                array (
                    'contactType' => 'technical',
                    'givenName' => 'ITS Security & Identity',
                    'emailAddress' =>
                        array (
                            0 => 'its-security@med.cornell.edu',
                        ),
                ),
        ),
    'metadata-set' => 'saml20-idp-remote',
    'SingleSignOnService' =>
        array (
            0 =>
                array (
                    'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Redirect',
                    'Location' => 'https://login.weill.cornell.edu/idp/profile/SAML2/Redirect/SSO',
                ),
        ),
    'SingleLogoutService' =>
        array (
            0 =>
                array (
                    'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Redirect',
                    'Location' => 'https://login.weill.cornell.edu/idp/profile/SAML2/Redirect/SLO',
                ),
        ),
    'ArtifactResolutionService' =>
        array (
        ),
    'keys' =>
        array (
            0 =>
                array (
                    'encryption' => false,
                    'signing' => true,
                    'type' => 'X509Certificate',
                    'X509Certificate' => 'MIIEhzCCA2+gAwIBAgIJAL0+jmniqPpSMA0GCSqGSIb3DQEBCwUAMIHZMQswCQYDVQQGEwJVUzERMA8GA1UECAwITmV3IFlvcmsxETAPBgNVBAcMCE5ldyBZb3JrMSYwJAYDVQQKDB1XZWlsbCBDb3JuZWxsIE1lZGljYWwgQ29sbGVnZTEtMCsGA1UECwwkSVRTIC0gU2VjdXJpdHkgJiBJZGVudGl0eSBNYW5hZ2VtZW50MSAwHgYDVQQDDBdsb2dpbi53ZWlsbC5jb3JuZWxsLmVkdTErMCkGCSqGSIb3DQEJARYcaXRzLXNlY3VyaXR5QG1lZC5jb3JuZWxsLmVkdTAeFw0xNjA4MTAxNzUwMDNaFw0yNjA4MTAxNzUwMDNaMIHZMQswCQYDVQQGEwJVUzERMA8GA1UECAwITmV3IFlvcmsxETAPBgNVBAcMCE5ldyBZb3JrMSYwJAYDVQQKDB1XZWlsbCBDb3JuZWxsIE1lZGljYWwgQ29sbGVnZTEtMCsGA1UECwwkSVRTIC0gU2VjdXJpdHkgJiBJZGVudGl0eSBNYW5hZ2VtZW50MSAwHgYDVQQDDBdsb2dpbi53ZWlsbC5jb3JuZWxsLmVkdTErMCkGCSqGSIb3DQEJARYcaXRzLXNlY3VyaXR5QG1lZC5jb3JuZWxsLmVkdTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALd/2R1oC+LOG5vr70a+9aHn8eWIuQ29liHSvLjl2tsIAYH8FTDjesl0pqAYkzYz7ENIr8RnHbWPpBQyNmS9Z35x66aUfLaJB3clFo+GytDNhDgrojEZpHuyuiF015pHjVTVZYZwTiwdRsG13/lIieC//zvEiJwNF+5kE7dudxktYrYguy2nDEpeAr4wrNDcNaIcLr7hzb9NSCwe7qRyiN0w5BNS1MInjBlKmlxP3D07BEb5OWECnOZ7ZV7t0sxBGE2OAexWXT5cbsqkvxCUL8UXM4rW2z81IEIhcVFZtWtdExt1YiGp0WLLWm4ccHWaGWRbaN1F8Gc1kPbkhLZvKrcCAwEAAaNQME4wHQYDVR0OBBYEFKRkbXVfS70Gh2hcd3QsDNuYtOxfMB8GA1UdIwQYMBaAFKRkbXVfS70Gh2hcd3QsDNuYtOxfMAwGA1UdEwQFMAMBAf8wDQYJKoZIhvcNAQELBQADggEBAH4/q+0mZnMBSRjcyqxuF6azRG6dfp4Ui3JTcJjJ29heTZjPuGQP5dS924b18N+lj5T9R5gEkB0H34VjCGv6BOmFWSh56eBVs7aihSYOijELsZLawlSH89s/reTH6Jj7RUfggtgSCgNzOQNpQPvCBKe1253w942NeCnHQg9uyzP80olECbS3eaTSTyn0AxNjiZ+fLT9FAIsPR3q1mGXuKyBXt4gEVNyJzcnZ8KC/K/HhsoTUJ0hppdSmybJhhTY+FjgYxXuNJsapLD8T0AoWK00DOS+3kaqPPloiGyuil/RxIV80DAK8Ofmlnj5it09WJ2ijhN+xCBiJpyKMCwf9zYE=',
                ),
            1 =>
                array (
                    'encryption' => true,
                    'signing' => false,
                    'type' => 'X509Certificate',
                    'X509Certificate' => 'MIIEhzCCA2+gAwIBAgIJAL0+jmniqPpSMA0GCSqGSIb3DQEBCwUAMIHZMQswCQYDVQQGEwJVUzERMA8GA1UECAwITmV3IFlvcmsxETAPBgNVBAcMCE5ldyBZb3JrMSYwJAYDVQQKDB1XZWlsbCBDb3JuZWxsIE1lZGljYWwgQ29sbGVnZTEtMCsGA1UECwwkSVRTIC0gU2VjdXJpdHkgJiBJZGVudGl0eSBNYW5hZ2VtZW50MSAwHgYDVQQDDBdsb2dpbi53ZWlsbC5jb3JuZWxsLmVkdTErMCkGCSqGSIb3DQEJARYcaXRzLXNlY3VyaXR5QG1lZC5jb3JuZWxsLmVkdTAeFw0xNjA4MTAxNzUwMDNaFw0yNjA4MTAxNzUwMDNaMIHZMQswCQYDVQQGEwJVUzERMA8GA1UECAwITmV3IFlvcmsxETAPBgNVBAcMCE5ldyBZb3JrMSYwJAYDVQQKDB1XZWlsbCBDb3JuZWxsIE1lZGljYWwgQ29sbGVnZTEtMCsGA1UECwwkSVRTIC0gU2VjdXJpdHkgJiBJZGVudGl0eSBNYW5hZ2VtZW50MSAwHgYDVQQDDBdsb2dpbi53ZWlsbC5jb3JuZWxsLmVkdTErMCkGCSqGSIb3DQEJARYcaXRzLXNlY3VyaXR5QG1lZC5jb3JuZWxsLmVkdTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALd/2R1oC+LOG5vr70a+9aHn8eWIuQ29liHSvLjl2tsIAYH8FTDjesl0pqAYkzYz7ENIr8RnHbWPpBQyNmS9Z35x66aUfLaJB3clFo+GytDNhDgrojEZpHuyuiF015pHjVTVZYZwTiwdRsG13/lIieC//zvEiJwNF+5kE7dudxktYrYguy2nDEpeAr4wrNDcNaIcLr7hzb9NSCwe7qRyiN0w5BNS1MInjBlKmlxP3D07BEb5OWECnOZ7ZV7t0sxBGE2OAexWXT5cbsqkvxCUL8UXM4rW2z81IEIhcVFZtWtdExt1YiGp0WLLWm4ccHWaGWRbaN1F8Gc1kPbkhLZvKrcCAwEAAaNQME4wHQYDVR0OBBYEFKRkbXVfS70Gh2hcd3QsDNuYtOxfMB8GA1UdIwQYMBaAFKRkbXVfS70Gh2hcd3QsDNuYtOxfMAwGA1UdEwQFMAMBAf8wDQYJKoZIhvcNAQELBQADggEBAH4/q+0mZnMBSRjcyqxuF6azRG6dfp4Ui3JTcJjJ29heTZjPuGQP5dS924b18N+lj5T9R5gEkB0H34VjCGv6BOmFWSh56eBVs7aihSYOijELsZLawlSH89s/reTH6Jj7RUfggtgSCgNzOQNpQPvCBKe1253w942NeCnHQg9uyzP80olECbS3eaTSTyn0AxNjiZ+fLT9FAIsPR3q1mGXuKyBXt4gEVNyJzcnZ8KC/K/HhsoTUJ0hppdSmybJhhTY+FjgYxXuNJsapLD8T0AoWK00DOS+3kaqPPloiGyuil/RxIV80DAK8Ofmlnj5it09WJ2ijhN+xCBiJpyKMCwf9zYE=',
                ),
        ),
    'scope' =>
        array (
            0 => 'med.cornell.edu',
        ),
);

//Test Metadata
$metadata['https://login-test.weill.cornell.edu/idp'] = array (
    'entityid' => 'https://login-test.weill.cornell.edu/idp',
    'description' =>
        array (
            'en' => 'Weill Cornell Medicine (test)',
        ),
    'OrganizationName' =>
        array (
            'en' => 'Weill Cornell Medicine (test)',
        ),
    'name' =>
        array (
            'en' => 'Weill Cornell Medicine (test)',
        ),
    'OrganizationDisplayName' =>
        array (
            'en' => 'Weill Cornell Medicine (test)',
        ),
    'url' =>
        array (
            'en' => 'http://weill.cornell.edu/',
        ),
    'OrganizationURL' =>
        array (
            'en' => 'http://weill.cornell.edu/',
        ),
    'contacts' =>
        array (
            0 =>
                array (
                    'contactType' => 'technical',
                    'givenName' => 'ITS Security & Identity',
                    'emailAddress' =>
                        array (
                            0 => 'its-security@med.cornell.edu',
                        ),
                ),
        ),
    'metadata-set' => 'saml20-idp-remote',
    'SingleSignOnService' =>
        array (
            0 =>
                array (
                    'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Redirect',
                    'Location' => 'https://login-test.weill.cornell.edu/idp/profile/SAML2/Redirect/SSO',
                ),
        ),
    'SingleLogoutService' =>
        array (
            0 =>
                array (
                    'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Redirect',
                    'Location' => 'https://login-test.weill.cornell.edu/idp/profile/SAML2/Redirect/SLO',
                ),
        ),
    'ArtifactResolutionService' =>
        array (
        ),
    'keys' =>
        array (
            0 =>
                array (
                    'encryption' => false,
                    'signing' => true,
                    'type' => 'X509Certificate',
                    'X509Certificate' => 'MIIEkTCCA3mgAwIBAgIJAIM3E9bM6upbMA0GCSqGSIb3DQEBCwUAMIHeMQswCQYDVQQGEwJVUzERMA8GA1UECAwITmV3IFlvcmsxETAPBgNVBAcMCE5ldyBZb3JrMSYwJAYDVQQKDB1XZWlsbCBDb3JuZWxsIE1lZGljYWwgQ29sbGVnZTEtMCsGA1UECwwkSVRTIC0gU2VjdXJpdHkgJiBJZGVudGl0eSBNYW5hZ2VtZW50MSUwIwYDVQQDDBxsb2dpbi10ZXN0LndlaWxsLmNvcm5lbGwuZWR1MSswKQYJKoZIhvcNAQkBFhxpdHMtc2VjdXJpdHlAbWVkLmNvcm5lbGwuZWR1MB4XDTE2MDgxMDE3NTExMloXDTI2MDgxMDE3NTExMlowgd4xCzAJBgNVBAYTAlVTMREwDwYDVQQIDAhOZXcgWW9yazERMA8GA1UEBwwITmV3IFlvcmsxJjAkBgNVBAoMHVdlaWxsIENvcm5lbGwgTWVkaWNhbCBDb2xsZWdlMS0wKwYDVQQLDCRJVFMgLSBTZWN1cml0eSAmIElkZW50aXR5IE1hbmFnZW1lbnQxJTAjBgNVBAMMHGxvZ2luLXRlc3Qud2VpbGwuY29ybmVsbC5lZHUxKzApBgkqhkiG9w0BCQEWHGl0cy1zZWN1cml0eUBtZWQuY29ybmVsbC5lZHUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCjnXimV2HPxAIaHXsiqjoiUAdpLIF2j3aCeQAvNZvZGiksMlHDMtf6wRUFlqOmfqb3JJiXHj+oEh3zCxEdYS5sDm2110z3A3ZN53pCShLKS3IFRATmxtujT42EvihyK3RJz4u/slwzjiRScicZ3fcLA0o0V4B6FxCHA7AZyvsZ+bI/B8c3cA0D0c0NhmRVKYqZ5ae5Qwi9ikNrn9dOCU2wPIOL1U9pqmoBXRX948k6ZgJ6uFkNbc2XyOiQVfQXYgcXnSOtjzits6BBkCXQ9xuQHDV8f8AnRvq8F4gsPoTPpj9HX1W5Xn1YqdqdmTujYkE5qVDDmtpKfmZ2HhD3+v23AgMBAAGjUDBOMB0GA1UdDgQWBBSeQwGkdE4Qt8B8SfLY8dqr9u3xCjAfBgNVHSMEGDAWgBSeQwGkdE4Qt8B8SfLY8dqr9u3xCjAMBgNVHRMEBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQBufsPXhAi5tnPZXKuAKKvSJHUNavGWUqxmY3Yvd5aAKGZ0bm+aTs90/j+smmaRxFun2nJPpLNRqVWXrHkP7OA+ZRMOBBrtagWgk3wipM22o32vEvtByCiPTRPXvctguaIkBWUNQVwMp7d+ZT5YlXkiYfu9W2uPr7fyqicr3FVY/cYdJV6Ff5MBAVhQlJMJ2FGumT4AUxlIYKjM4qDzEc7xPJjkQzVDIRf8QcJCBahpSL0R9ddnGUit+CC2Az8E3BW+xxvoF+uIyryJ5m/U+TE5SUE7G72O1xfz4wvOys5Uf/jsUnEhCUyYHWASWA9JfrinohBFLc4KgQWnmmJIf7ZQ',
                ),
            1 =>
                array (
                    'encryption' => true,
                    'signing' => false,
                    'type' => 'X509Certificate',
                    'X509Certificate' => 'MIIEkTCCA3mgAwIBAgIJAIM3E9bM6upbMA0GCSqGSIb3DQEBCwUAMIHeMQswCQYDVQQGEwJVUzERMA8GA1UECAwITmV3IFlvcmsxETAPBgNVBAcMCE5ldyBZb3JrMSYwJAYDVQQKDB1XZWlsbCBDb3JuZWxsIE1lZGljYWwgQ29sbGVnZTEtMCsGA1UECwwkSVRTIC0gU2VjdXJpdHkgJiBJZGVudGl0eSBNYW5hZ2VtZW50MSUwIwYDVQQDDBxsb2dpbi10ZXN0LndlaWxsLmNvcm5lbGwuZWR1MSswKQYJKoZIhvcNAQkBFhxpdHMtc2VjdXJpdHlAbWVkLmNvcm5lbGwuZWR1MB4XDTE2MDgxMDE3NTExMloXDTI2MDgxMDE3NTExMlowgd4xCzAJBgNVBAYTAlVTMREwDwYDVQQIDAhOZXcgWW9yazERMA8GA1UEBwwITmV3IFlvcmsxJjAkBgNVBAoMHVdlaWxsIENvcm5lbGwgTWVkaWNhbCBDb2xsZWdlMS0wKwYDVQQLDCRJVFMgLSBTZWN1cml0eSAmIElkZW50aXR5IE1hbmFnZW1lbnQxJTAjBgNVBAMMHGxvZ2luLXRlc3Qud2VpbGwuY29ybmVsbC5lZHUxKzApBgkqhkiG9w0BCQEWHGl0cy1zZWN1cml0eUBtZWQuY29ybmVsbC5lZHUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCjnXimV2HPxAIaHXsiqjoiUAdpLIF2j3aCeQAvNZvZGiksMlHDMtf6wRUFlqOmfqb3JJiXHj+oEh3zCxEdYS5sDm2110z3A3ZN53pCShLKS3IFRATmxtujT42EvihyK3RJz4u/slwzjiRScicZ3fcLA0o0V4B6FxCHA7AZyvsZ+bI/B8c3cA0D0c0NhmRVKYqZ5ae5Qwi9ikNrn9dOCU2wPIOL1U9pqmoBXRX948k6ZgJ6uFkNbc2XyOiQVfQXYgcXnSOtjzits6BBkCXQ9xuQHDV8f8AnRvq8F4gsPoTPpj9HX1W5Xn1YqdqdmTujYkE5qVDDmtpKfmZ2HhD3+v23AgMBAAGjUDBOMB0GA1UdDgQWBBSeQwGkdE4Qt8B8SfLY8dqr9u3xCjAfBgNVHSMEGDAWgBSeQwGkdE4Qt8B8SfLY8dqr9u3xCjAMBgNVHRMEBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQBufsPXhAi5tnPZXKuAKKvSJHUNavGWUqxmY3Yvd5aAKGZ0bm+aTs90/j+smmaRxFun2nJPpLNRqVWXrHkP7OA+ZRMOBBrtagWgk3wipM22o32vEvtByCiPTRPXvctguaIkBWUNQVwMp7d+ZT5YlXkiYfu9W2uPr7fyqicr3FVY/cYdJV6Ff5MBAVhQlJMJ2FGumT4AUxlIYKjM4qDzEc7xPJjkQzVDIRf8QcJCBahpSL0R9ddnGUit+CC2Az8E3BW+xxvoF+uIyryJ5m/U+TE5SUE7G72O1xfz4wvOys5Uf/jsUnEhCUyYHWASWA9JfrinohBFLc4KgQWnmmJIf7ZQ',
                ),
        ),
    'scope' =>
        array (
            0 => 'med.cornell.edu',
        ),
);

