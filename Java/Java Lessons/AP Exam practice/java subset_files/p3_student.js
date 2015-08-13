function formatStudentTesting(){

	var loc = document.location.toString();
	d = loc.split('?');
	subject = document.getElementById(d[1]);

	if(subject){

		options = document.getElementById('student-testing').getElementsByTagName('option');
		for(j=1;j<options.length;j++){
			if(options[j].value.indexOf(d[1])>=0){
				options[j].className = 'current';
				options[j].selected = true;
				setParentsToCurrent(options[j],'lnav');
				break;
			}
		} 

		li = subject.getElementsByTagName('LI');

		for(j=0;j<li.length;j++){
			li[j].style.display = 'block';
			li[j].style.visibility = 'visible';
		} 
	}
}

function setParentsToCurrent(el){
	while(el.id != 'lnav'){
 		el = el.parentNode;
 		if((el.tagName == 'LI') && (el.className != 'hidden')){
			el.className = 'current';
		}
	}
}

function changeSubject(s){
	s.className = 'articlesection';
	s.selected = true;
	window.location.href = s.value;
}
