[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; 
$working_directory = (Get-Item -Path ".\").FullName; 
$wc = New-Object System.Net.WebClient; 
Invoke-WebRequest -Uri "https://github.com/Massdrop/mdloader/releases/download/1.0.3/applet-flash-samd51j18a.bin"; 
Invoke-WebRequest -Uri "https://github.com/Massdrop/mdloader/releases/download/1.0.3/mdloader_windows.exe"; 
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/valen214/Massdrop-Ctrl-Keyboard-Ripple-LED/master/.build/massdrop_ctrl_custom.hex"; 
start mdloader_windows.exe "-f -D massdrop_ctrl_custom.hex --restart" 
