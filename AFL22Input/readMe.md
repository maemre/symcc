# Testing
For this testing I used the AFL fuzzer to fuzz the original program to generate some "interesting" path conditions and the inputs that created these path condtions. I used the input "ID 22" as an original input to begin the experiment on.

# Inputs
Taking the original "interesting" input, I used some bitshifting and bit manipulation to create three pertubations of the input
- Pertubation 1: /6^B^@/U
- Pertubation 2: /2^D^@/S
- Pertubation 3: /8^B^C/3
# Path results
With these pertubations, I was able to generate the path condtions for each input and clean them with the `sexp-rewriter`. From my testing I found some generaliztions to show that two of the inputs took the same paths while the other one did not.
- The original input and `Pertubation 3` took the same route
- `Pertubation 1` and `Pertubation 2` took the same route
