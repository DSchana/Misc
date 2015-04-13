var canvas;
var canvasContext;
var ballX = 50;
var ballY = 300;
var ballSpeedX = 1;
var ballSpeedY = 1;
var e;
var playerY = 210;

window.onload = function() {
	console.log("Hello World!");
	canvas = document.getElementById('gameCanvas');
	canvasContext = canvas.getContext('2d');

	var fps = 120;
	setInterval(function() {
			updatePositions();
			drawEverything();
		}, 1000/fps);
}

function drawEverything() {
	// Background
	drawRect(0, 0, canvas.width, canvas.height, 'black');

	// Paddles
	drawRect(0, playerY, 10, 100, 'white');

	// Ball
	canvasContext.fillStyle = 'white';
	canvasContext.beginPath();
	canvasContext.arc(ballX, ballY, 10, 0, Math.PI*2, true);
	canvasContext.fill();
}

function drawRect(x, y, width, height, colour) {
	canvasContext.fillStyle = colour;
	canvasContext.fillRect(x, y, width, height);
}

function updatePositions() {
	e = window.event;

	if (ballY <= 10) {
		ballSpeedY = -ballSpeedY;
	} else if (ballY >= canvas.height-10) {
		ballSpeedY = -ballSpeedY;
	}
	
	//playerY = e.clientY;

	ballY += ballSpeedY;
	//ballX += ballSpeedX;
}