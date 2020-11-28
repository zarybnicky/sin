{ nixpkgs ? fetchTarball "https://github.com/NixOS/nixpkgs/archive/ffb3aab257e8851b558cdc6079241a7eb0c7239e.tar.gz"
}: let
  inherit (pkgs.nix-gitignore) gitignoreSourcePure;
  pkgs = import nixpkgs { overlays = [ overlay ]; };
  getSrc = gitignoreSourcePure [./.gitignore];
  overlay = final: prev: {
    haskellPackages = prev.haskellPackages.override (old: let
      inherit (final.haskell.lib) doJailbreak;
    in {
      overrides = pkgs.lib.composeExtensions (old.overrides or (_: _: {})) (hself: hsuper: {
        copilot-sin-demo = hself.callCabal2nix "copilot-sin-demo" (getSrc ./.) {};
        arduino-copilot = hself.callHackage "arduino-copilot" "1.5.2" {};
        copilot = doJailbreak (hself.callHackage "copilot" "3.1" {});
        copilot-language = doJailbreak (hself.callHackage "copilot-language" "3.1" {});
        copilot-libraries = doJailbreak (hself.callHackage "copilot-libraries" "3.1" {});
        copilot-theorem = doJailbreak (hself.callHackage "copilot-theorem" "3.1" {});
        bimap = hself.callCabal2nix "bimap" (getSrc ./deps/bimap) {};
      });
    });
  };
in {
  pkg = pkgs.haskellPackages.copilot-sin-demo;

  shell = pkgs.haskellPackages.shellFor {
    withHoogle = true;
    packages = p: [ p.copilot-sin-demo ];
    buildInputs = [
      pkgs.haskellPackages.cabal-install
      pkgs.haskellPackages.haskell-language-server
    ];
  };
}
