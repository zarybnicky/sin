arduino:
	cabal run demo-arduino-copilot
	xclip -selection c sin.ino

copilot:
	cabal run demo-copilot
	cat demo-copilot.c demo-copilot/scaffold.c > demo-copilot.sin
	sed -i 's/#include "demo-copilot.h"//' demo-copilot.sin
	sed -i 's/#include <stdint.h>//' demo-copilot.sin
	sed -i 's/#include <stdbool.h>//' demo-copilot.sin
	sed -i 's/#include <string.h>//' demo-copilot.sin
	xclip -selection c demo-copilot.sin
