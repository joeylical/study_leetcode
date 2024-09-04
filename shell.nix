with import <nixpkgs> {};
mkShell {
  buildInputs = [
    clang
    clang-tools
    gdb
  ];
  shellHook = ''
    PATH="${pkgs.clang-tools}/bin:$PATH"
  '';
}

