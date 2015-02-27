
function redBackground(tab) {
    var page = chrome.extension.getBackgroundPage();
    page.console.log('foo');

    chrome.tabs.executeScript({
      file: 'action.js'
    });
}

chrome.browserAction.onClicked.addListener(redBackground);