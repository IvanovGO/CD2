goal - 1837

//deconv
$ time ./cd2 3.t 33.t 1
Arg 3 received 1
Arg 2 received 33.t
Arg 1 received 3.t

real	0m15,280s
user	0m14,601s
sys	0m0,630s


//conv
time ./cd2 2.t 3.t
Arg 2 received 3.t
Arg 1 received 2.t

real	0m31,538s
user	0m29,133s
sys	0m0,810s


//atoi
$ time ./cd2 2.t 3.t
Arg 2 received 3.t
Arg 1 received 2.t

real	1m14,036s
user	1m10,629s
sys	0m2,630s


//just copy
$ time ./cd2 2.t 3.t
Arg 2 received 3.t
Arg 1 received 2.t

real	0m25,244s
user	0m23,580s
sys	0m1,139s

