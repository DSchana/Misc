var canvas;
var canvasContext;
var ballX = 50;
var ballY = 300;
var player1Y = 210;
var player2Y = 210;

const PADDLE_WIDTH = 10;
const PADDLE_HEIGHT = 100;
const PADDLE2_SPEED = 2;
const ballSpeedX = 3;
const ballSpeedY = 2;

window.onload = function() {
	console.log("Hello World!");
	canvas = document.getElementById('gameCanvas');
	canvasContext = canvas.getContext('2d');
	canvas.addEventListener('mousemove', 
		function(evt) {
			var mousePos = getMousePos(evt);
			if ((mousePos.y - PADDLE_HEIGHT/2) >= 0 && (mousePos.y - PADDLE_HEIGHT/2) <= canvas.height - PADDLE_HEIGHT) {
				player1Y = mousePos.y - PADDLE_HEIGHT/2;
			}
		});

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
	drawRect(0, player1Y, PADDLE_WIDTH, PADDLE_HEIGHT, 'white');
	drawRect(canvas.width-10, player2Y, PADDLE_WIDTH, PADDLE_HEIGHT, 'white');

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
	if (ballY <= 10 || ballY >= canvas.height-10) {
		ballSpeedY = -ballSpeedY;
	}

	if ((player2Y - PADDLE_HEIGHT/2) > ballY && player2Y >= 0) {
		player2Y -= PADDLE2_SPEED;
	} else if ((player2Y - PADDLE_HEIGHT/2) < ballY && player2Y <= canvas.height - PADDLE_HEIGHT) {
		player2Y += PADDLE2_SPEED;
	}

	ballY += ballSpeedY;
	ballX += ballSpeedX;
}

function getMousePos(evt) {
	var rect = canvas.getBoundingClientRect();
	var root = document.documentElement;
	var mx = evt.clientX - rect.left - root.scrollLeft;
	var my = evt.clientY - rect.top - root.scrollTop;

	return {
		x:mx,
		y:my
	};
}