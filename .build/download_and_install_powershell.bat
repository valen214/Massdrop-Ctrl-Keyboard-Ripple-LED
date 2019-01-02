
echo [Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; > download_and_install_powershell.ps1
echo $working_directory = (Get-Item -Path ".\").FullName; >> download_and_install_powershell.ps1
echo $wc = New-Object System.Net.WebClient; >> download_and_install_powershell.ps1
echo Invoke-WebRequest -Uri "https://github.com/Massdrop/mdloader/releases/download/1.0.3/applet-flash-samd51j18a.bin"; >> download_and_install_powershell.ps1
echo Invoke-WebRequest -Uri "https://github.com/Massdrop/mdloader/releases/download/1.0.3/mdloader_windows.exe"; >> download_and_install_powershell.ps1
echo Invoke-WebRequest -Uri "https://raw.githubusercontent.com/valen214/Massdrop-Ctrl-Keyboard-Ripple-LED/master/.build/massdrop_ctrl_custom.hex"; >> download_and_install_powershell.ps1
echo start mdloader_windows.exe "-f -D massdrop_ctrl_custom.hex --restart" >> download_and_install_powershell.ps1
powershell -Command "Set-ExecutionPolicy RemoteSigned"
powershell -File download_and_install_powershell.ps1