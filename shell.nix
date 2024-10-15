with import <nixpkgs> {};
mkShell {
  buildInputs = [
    clang
    clang-tools
    lldb
  ];
  shellHook = ''
    PATH="${pkgs.clang-tools}/bin:$PATH"
  '';
}

