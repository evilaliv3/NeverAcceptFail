# NEVER_ACCEPT_FAIL is a C Macro developed with aim to improve software security in critical circumstances.

The Macro it's proposed as a POC (proof of concept), for situations
where the computer programmer is completely self confident about the
return value of a function an so wants to give a last resort
in cases where the result doesn't match the expectations.

# Typical usage:

        uint32_t critical_function(const char* par) {
            printf("hello world");
            return 1;
        }

        NEVER_ACCEPT_FAIL(critical_function, 1, "poc example");

# GPG public keys

    $ gpg --keyserver pgp.mit.edu --recv-key D9A950DE
    $ gpg --fingerprint --list-keys D9A950DE
    pub   1024D/D9A950DE 2009-05-10 [expires: 2014-05-09]
          Key fingerprint = C1ED 5C8F DB6A 1C74 A807  5695 91EC 9BB8 D9A9 50DE
    uid                  Giovanni Pellerano <giovanni.pellerano@evilaliv3.org>
    sub   4096g/50A7F150 2009-05-10 [expires: 2014-05-09]
