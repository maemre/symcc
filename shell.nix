{ config, lib, pks, ...}:
with import <nixpkgs> {};
llvmPackages_14.stdenv.mkDerivation {
  name = "clang-nix-shell";
  buildInputs = [
    cargo
    clang
    cmake
    z3
    buildPackages.llvm_14
    ninja
    python2
    zlib
    lit
    python310
    python310Packages.z3
    libcxx
  ];
}
