with import <nixpkgs> {};
mkShell {
  buildInputs = [
    clang
    clang-tools
  ];
  shellHook = ''
    PATH="${pkgs.clang-tools}/bin:$PATH"
  '';
}

