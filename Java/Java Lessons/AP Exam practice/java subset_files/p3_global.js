/* ----------------------------- BROWSER SNIFFING VARS ----------------------------- */
var agt      = navigator.userAgent.toLowerCase();
var appVer   = navigator.appVersion.toLowerCase();
var is_minor = parseFloat(appVer);
var is_major = parseInt(is_minor);

var is_opera = (agt.indexOf("opera") != -1);

var is_safari = ((agt.indexOf('safari')!=-1)&&(agt.indexOf('mac')!=-1))?true:false;

var iePos  = appVer.indexOf('msie');
if (iePos !=-1) {
   is_minor = parseFloat(appVer.substring(iePos+5,appVer.indexOf(';',iePos)))
   is_major = parseInt(is_minor);
}
var is_ie   = (iePos!=-1);
var is_ie5   = (is_ie && is_major == 5);

var is_win   = ( (agt.indexOf("win")!=-1) || (agt.indexOf("16bit")!=-1) );
var is_mac    = (agt.indexOf("mac")!=-1);
var is_ie5up = (is_ie && is_minor >= 5);


/* ----------------------------- NAVIGATION ----------------------------- */


function appendIndexToURL(url){
	var re = /\/$/;
	if(re.test(url)){
		url += 'index.html';
	}
	return url;
}

function setCurrent(el){ el.className += (el.className=='') ? 'current' : ' current'; }

function NavDisplay(){
	this.lnav.style.display  	   = 'block';
	this.lnav.style.visibility   = 'visible';
}

function NavFindCurrent(el){

	var loc = document.location.toString();
	loc     = appendIndexToURL(loc);
	anchors = el.getElementsByTagName('A');

	for(var i=0;i<anchors.length;i++){
		if(loc.indexOf(anchors[i].href)>=0){
			return anchors[i];
		}
	}

	// if we get here, no match found in container div for current page
	return null;
}

function setParents(el){
	while(el.id != this.lnavId){
		el = el.parentNode;
		if((el.tagName == 'LI') && (el.className != 'hidden')){
			setCurrent(el);
		}
	}
}

function NavFormat(){

	curr = el = NavFindCurrent(this.lnav);
	if(curr){
		setCurrent(curr);
	}
	else{
		// no match found
		return;
	}

	try {
		setParents(el);
	}
	catch(e){ return; }


	if(curr.parentNode.className == 'hidden'){
		try {
			// this is for ie. ie doesn't return null if the object doesn't exist.
			if(curr.parentNode.parentNode.previousSibling.previousSibling){
				setCurrent(curr.parentNode.parentNode.previousSibling.previousSibling);
			}
		}
		catch(e){ return; }
	}
}

function NavIsIndex(id){
	el      = document.getElementById(id);
	re      = new RegExp('http:\/\/' + document.domain + '(.*)');
	reRes   = re.exec(document.location);
	rURL    = reRes[1];
	loc     = appendIndexToURL(rURL);
	return (el.innerHTML.indexOf(rURL)>=0) ? true : false;
}

function NavTNavIs(id){ setCurrent(document.getElementById(id)); }

function Nav(id) {

// this object traverses a collection of nested lists that identify pages and urls used for navigating
// across the site. altering the states (presentation of items in the list) based on whether the list
// item's anchor tag matches the document.location or is related to that list item

// write the hidden styles
	document.write('<style type="text/css">'
	+ '#lnav ul li ul,'
	+ '#lnav ul li.current ul li ul,'
	+ '#lnav ul li.current ul li.current ul li ul'
	+ '{ visibility:hidden; display:none; }'
	+ '</style>'
	);

//
// PROPERTIES
//
// identifies the leftnav section to which this lnav belongs
	this.lnavId = id;

// the left navigation container element
 	this.lnav   = document.getElementById(id);


// hide the entire list prior to altering states of list items
	this.lnav.style.display  	  = 'none';
	this.lnav.style.visibility  = 'hidden';

//
// METHODS
//
	this.pgIsIndex   = NavIsIndex;
	this.format      = NavFormat;
	this.findCurrent = NavFindCurrent;
	this.display     = NavDisplay;
	this.tnavIs      = NavTNavIs;
}


/* ----------------------------------------------------------------- toggleMyList() */


i      = new Image();
i.src  = '/common/shared/images/icon_contract.gif';

function toggleMyList(img,id){
	var el = document.getElementById(id);

	if(el.className == 'hidden'){
		el.className = '';
		img.src = '/common/shared/images/icon_contract.gif';
	} else {
		el.className = 'hidden';
		img.src = '/common/shared/images/icon_expand.gif';
	}
}


/* ------------------------------------------------------------------- cookieTime() */

function cookieTime(days){
  var now = new Date();
  var exp = new Date();
  var x   = Date.parse(now) + days*24*60*60*1000;
  exp.setTime(x);
  str = exp.toUTCString();
  re = '/(\d\d)\s(\w\w\w)\s\d\d(\d\d))/';
  return str.replace(re,"$1-$2-$3");
}

/* ----------------------------------------------------------------------- popup() */

//popup
function popup(url,title,w,h,r,s,m,t,l) {
	//if vars aren't provided, use these defaults
	if (title==null) {
		title = 'popup';
	} if (w==null) {
		w=600;
	} if (h==null) {
		h=400;
	} if (r==null) {
		r='yes';
	} if (s==null) {
		s='yes';
	} if (m==null) {
		m='no';
	} if (t==null) {
		t='no';
	} if (l==null) {
		l='no';
	}
	vars = 'width='+w+',height='+h+',resizable='+r+',scrollbars='+s+',menubar='+m+',toolbar='+t+',location='+l;
	var newWin = window.open(url,title,vars);
	newWin.focus();
	return false;
}

/* ---------------------------------------------------------------- openInParent() */
//loads url in opener
function openInParent(loc) 	{
	window.opener.location=loc;
	return false;
}


/* ------------------------------------------------------------- clearRadioGroup() */
//clears radio buttons in group
function clearRadioGroup(formName,groupName){
	var rb;

	for (i = 0; i < eval("document.forms[formName]." + groupName + ".length"); i++) {
		rb = eval("document.forms[formName]." + groupName + "[i];");
		if (rb.checked) {
			rb.checked = false;
		}
	}

}


/* ------------------------------------------------------------- writeCurrentYr() */
function writeCurrentYr(){
	var now = new Date();
	document.write(now.getFullYear());
}



/* ----------------------------- ID HOVER PSEUDO CLASS FIXES ----------------------------- */
/*
Since PC IE versions 6 and below don't support the CSS :hover pseudo class on any element
but <a> we use these functions to apply onMouseOver and onMouseOut to the elements
*/

// mouse overs for form buttons
function buttonhover() {

	for(i=0; i<document.forms.length; i++){

		for(j=0; j<document.forms[i].elements.length; j++){

			if(document.forms[i].elements[j].className == 'button'){
				button = document.forms[i].elements[j];
				button.onmouseover = function() { this.className = 'buttonover'; }
				button.onmouseout  = function() { this.className = 'button'; }
			}
		}
	}
}

/* ----------------------------- STYLE FIXES ----------------------------- */

// ie has a bug that indents text about 2 or 3 pixels when it has a floated element next to it.  This function adds a single pixel wide spacer to eliminate the letter spacing
function ieFloatFix(){

	arg = ieFloatFix.arguments;

	if((is_win)&&(is_ie5up)&&(!is_opera)){

		var divId = (arg.length == 0) ? 'content' : divId = arg[0];

		if(document.getElementById('left')){
			el           = document.getElementById(divId);
			w            = el.offsetWidth - 1;
			el.innerHTML = '<div id="iefloatfix" style="float:left; width='+ w +'px;">' + document.getElementById(divId).innerHTML + '</div>';
		}

		elRight  = document.getElementById("right");
		elMiddle = document.getElementById("middle");

		if(elRight && elMiddle){
			if(elRight.offsetHeight > elMiddle.offsetHeight){
				elMiddle.style.height = elRight.offsetHeight;
			}
		}
	}
}



function isPopup(){
	el = document.getElementById('outer');
	return (el.className.indexOf("popup") >=0) ? true : false;
}



function setPageHeight(){
	// executed by footer.js
	var c = null;

	if(is_ie) {
		var ar = document.getElementsByTagName('DIV');
		for(var i=0;i<ar.length;i++){
			if(ar[i].id == 'content'){	c = ar[i]; }
		}
	}
	else { c = document.getElementById('content'); }

	if(c && (c.offsetHeight < 240)) {
		c.style.height = '240px';
		if(is_ie) {
			c.style.width = (document.getElementById('left')) ? '540px' : 'auto';
		}
	}
}



function writeUtilityScript(){
	re           = new RegExp('^https');
	var protocol = (re.test(document.location)) ? 'https' : 'http';

	document.write('<script type="text/javascript" src="' + protocol + '://apps.collegeboard.com/javascript/ut_utility.js"></' + 'script>');
}



function writeProcessVisitorCall(){
	document.write('<script type="text/javascript">processVisitor();</' + 'script>');
}


function insertPrintLogo(l){
	el               = document.getElementById('header');
  if(el){
    html           = el.innerHTML;
	  if(!html.match(/<img/i)){
	  	html         = html.replace(/<h1>(<a.*<\/a>)<\/h1>/i,'<h1>'+l+'$1</h1>');
    }
    el.innerHTML   = html;
	}
}

function footerJS(){

	// these functions are called with every page load after all other html is rendered
	// order is important. do not change without thorough testing...

	if(!isPopup()){	setPageHeight(); }

	ieFloatFix();

	if(is_ie5up){ buttonhover(); }

	var iType = (document.getElementById('footer').innerHTML.match(/#prof/)) ? '_prof' : '';
	var iSrc  = '/common/shared/images/logos/logo_small_print'+iType+'.gif';
	var plogo = new Image();
	plogo.src = iSrc;
	var l ='<img src="'+iSrc+'" style="height:'+plogo.height+'px;width:'+plogo.width+'px;" alt="CollegeBoard.com" title="CollegeBoard.com" />';

	insertPrintLogo(l);

	linksInNewWindow();

	//print pages have a special stylesheet
	if(window.name == "printview"){
		document.write('<link rel="stylesheet" type="text/css" href="/common/shared/css/printFriendly.css" />');
    if(is_ie5up || is_safari){
		  window.onbeforeprint = document.getElementById('header').innerHTML = l;
		}
	}

	if(is_safari){
		document.getElementById('sitenav').style.height        = '21px';
		document.getElementById('site-links').style.paddingTop = '0';
		document.getElementById('visitornav').style.paddingTop = '0';
		document.getElementById('q').style.fontSize            = '9px';
	}

	var mcs = document.getElementById('mycsearch');
	if(mcs){
		if(mcs.innerHTML.match('logout.jsp')){ mcs.style.borderBottom = '1px solid #ccc'; }
	}

	runFunctionArray();
	writeProcessVisitorCall();
}



function printFriendly(){
	var qStr = (document.location.toString().indexOf('?')>=0) ? '&print=true' : '?print=true';
	(window.name == 'printview') ? window.print() : popup(window.location+qStr,'printview','700','600');
	return false;
}



/*
set links to open in a new window for divs specified in the array (if defined)
*/

function linksInNewWindow() {

	if(window.openLinksInNewWindowFor){

		d         = window.openLinksInNewWindowFor;

		for(j=0;j<d.length;j++) {

			el      = document.getElementById(d[j]);
			anchors = el.getElementsByTagName('A');

			for(var i=0;i<anchors.length;i++){
				anchors[i].onclick = function nw(){ return popup(this.href,'app',800,600,'yes','yes','yes','yes','yes'); };
			}
		}
	}
}


/* ===================================================================================================
	function array. a way to add functions to any page to run on load (without using the onload event.
	onload event reserved for reston. functionArray's functions are executed by footerJS()
  ====================================================================================================*/

var funtionArray = new Array();

function appendToFunctionArray(f){
	funtionArray[funtionArray.length] = f;
}

function runFunctionArray(){
	for(var i=0;i<funtionArray.length;i++){
		funtionArray[i]();
	}
}
/*====================================================================================================*/




/* ===========================================================================================
		code is excuting below this point
   =========================================================================================== */

/*
 fix classes with background images for ie5 by redefining it.
*/
function noArrow() { return (document.layers || (is_win && is_ie && (is_minor<5.50))); }

if(noArrow()){
	document.write('<style type="text/css">' +
	'.arrow' +
	',.button' +
	',.buttonover' +
	',.navLeft' +
	',.navRight' +
	'{background-image: none !important; padding-left: 0px !important;}' +
	'</style>');
}

// set opera specific styles
if (is_opera){
	document.write(
	'<style type="text/css">' +
	'#tnav ul { float:none; }' +
	'#tnav li { float:none; }' +
	'</style>'
	);
}

//set Mac specific styles
if (is_mac){
	document.write(
	'<style type="text/css">' +
	'#contenthead.wrap { padding-top:18px; }' +
	'#tnav li a.wrap { padding: 4px 5px 3px 10px; line-height:auto }' +
	'#content a.button { padding-top: 2px; padding-bottom: 3px; }' +
	'#content form input.button, #content form input.buttonover { padding-top: 2px; }' +
	'</style>'
	);

	/*
	change styles for IE 5.0 Mac OS 9
	IE 5.0 (mac) doesn't like the top nav layout as is.
	For some reason having a float: left in the <li> and the <a> messed up IE5.0.
	The line below fixes the problems
	*/
	if (is_ie5){
		document.write(
		'<style type="text/css">' +
		'#tnav ul li { float: none; }' +
		'.sectionnav ul li { float: none; }' +
		'</style>'
		);
	}
}



/*
preload this array if defined
i.e. preloadTheseImages = new Array(...);
*/

if(window.preloadTheseImages){
	a      = preloadTheseImages;
	loaded = new Array(a.length);
	for(i=0;i<a.length;i++){
		loaded[i]     = new Image();
	  loaded[i].src = a[i];
	}
}

writeUtilityScript();

