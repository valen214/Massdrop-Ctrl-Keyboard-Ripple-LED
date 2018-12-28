

curl -L -O "https://github.com/Massdrop/mdloader/releases/download/1.0.3/applet-flash-samd51j18a.bin"
curl -L -O "https://github.com/Massdrop/mdloader/releases/download/1.0.3/mdloader_windows.exe"
curl -L -O "https://raw.githubusercontent.com/valen214/Massdrop-Ctrl-Keyboard-Ripple-LED/master/.build/massdrop_ctrl_custom.hex"
call mdloader_windows.exe -f -D massdrop_ctrl_custom.hex --restart