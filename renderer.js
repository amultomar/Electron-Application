const { ipcRenderer } = require('electron');

document.getElementById('send-request').addEventListener('click', () => {
  const input = 'Hello from renderer!';
  ipcRenderer.send('backend-request', input);
});

ipcRenderer.on('backend-response', (event, response) => {
  document.getElementById('response').innerHTML = response;
});