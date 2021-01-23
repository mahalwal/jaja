/* 
Scroll using the a/z key after deleting the overlaying elements of a soft paywall. Applicable on websites where scrolling is disabled
*/


function KeyPress(e) {
  var evtobj = window.event? event : e
  if (evtobj.keyCode == 90) {
    window.scrollBy(0, 100) 
  }
  if (evtobj.keyCode == 65) {
    window.scrollBy(0, -100) 
  }
}

document.onkeydown = KeyPress;
