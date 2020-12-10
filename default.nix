{ nixpkgs ? fetchTarball "https://github.com/NixOS/nixpkgs/archive/ffb3aab257e8851b558cdc6079241a7eb0c7239e.tar.gz"
}: let
  inherit (pkgs.nix-gitignore) gitignoreSourcePure;
  pkgs = import nixpkgs { overlays = [ overlay ]; };
  getSrc = gitignoreSourcePure [./.gitignore];
  overlay = final: prev: {
    haskell = prev.haskell // {
      packageOverrides = prev.lib.composeExtensions (prev.haskell.packageOverrides or (_: _: {})) (hself: hsuper: {
        demo-arduino-copilot = hself.callCabal2nix "demo-arduino-copilot" (getSrc ./demo-arduino-copilot) {};
        demo-copilot = hself.callCabal2nix "demo-copilot" (getSrc ./demo-copilot) {};
        arduino-copilot = hself.callHackage "arduino-copilot" "1.5.2" {};

        copilot = prev.haskell.lib.doJailbreak (hself.callHackage "copilot" "3.1" {});
        copilot-language = prev.haskell.lib.doJailbreak (hself.callHackage "copilot-language" "3.1" {});
        copilot-libraries = prev.haskell.lib.doJailbreak (hself.callHackage "copilot-libraries" "3.1" {});
        copilot-theorem = prev.haskell.lib.doJailbreak (hself.callHackage "copilot-theorem" "3.1" {});
        bimap = hself.callCabal2nix "bimap" (getSrc ./deps/bimap) {};
      });
    };
  };
in {
  pkg = pkgs.haskellPackages.copilot-sin-demo;

  shell = pkgs.haskellPackages.shellFor {
    withHoogle = true;
    packages = p: [ p.demo-copilot p.demo-arduino-copilot ];
    buildInputs = [
      pkgs.haskellPackages.cabal-install
      pkgs.haskellPackages.haskell-language-server
      pkgs.ino
    ];
  };
}
