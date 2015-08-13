//=============================================================================
// Filename......: ut_utility.js
//
// Description...: Check for VisitorID
//
// URL Type......: Non-Secure
//=============================================================================
function getCookieDomain()
{
   return 'collegeboard.com';
}

function DisabledCookies()
{
   var testCookie = 'CB_COOKIE';
   var today = new Date();
   var expires = new Date(today.getTime() + (86400000)); // + 1 day
   document.cookie = testCookie + '=AAAA;expires='  + expires.toGMTString() + '; path=/';
   var pos= document.cookie.indexOf(testCookie + '=');

   // 1 = cookie disabled; 0 = cookie enabled
   return (pos = pos<0 ? 1 : 0);
}

function processVisitor()
{
   if (document.cookie.indexOf('CB_SESSION_ID') < 0)
   {
      var today = new Date();
      var time = today.getTime();
      var random = Math.random();
      var sessionID = time + '.9';
      sessionID = sessionID + random;
      document.cookie = 'CB_SESSION_ID=' + escape(sessionID) + '; path=/;domain=' + getCookieDomain();
   }

   if (document.cookie.indexOf('VISITOR_ID') < 0)
   {
      window.open('http://apps.collegeboard.com/ut/ProcessVisitor.jsp?url=' + escape(document.URL) + '&DisabledCookies=' + DisabledCookies(), '', 'width=100,height=100,top=50000,left=50000,resizable=1,scrollbars=1');
   }
}
