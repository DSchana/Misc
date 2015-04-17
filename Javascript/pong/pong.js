var canvas;
var canvasContext;
var ballX = 50;
var ballY = 300;
var ballSpeedX = 3;
var ballSpeedY = 2;
var player1Y = 210;
var player2Y = 210;
var player1Score = 0;
var player2Score = 0;
var showWinScreen = false;

const PADDLE_WIDTH = 10;
const PADDLE_HEIGHT = 100;
const PADDLE2_SPEED = 2;

window.onload = function() {
	console.log("Hello World!");
	canvas = document.getElementById('gameCanvas');
	canvasContext = canvas.getContext('2d');

	canvas.addEventListener('mousedown', mouseClick);

	canvas.addEventListener('mousemove', 
		function(evt) {
			var mousePos = getMousePos(evt);
			if ((mousePos.y - PADDLE_HEIGHT/2) >= 0 && (mousePos.y - PADDLE_HEIGHT/2) <= canvas.height - PADDLE_HEIGHT) {
				player1Y = mousePos.y - PADDLE_HEIGHT/2;
			}
		});

	var fps = 120;
	setInterval(function() {
			if (showWinScreen) {
				if (player1Score > player2Score) {
					canvasContext.fillText("Player 1 Won!", canvas.width/4 + 50, 100);
				}
				else {
					canvasContext.fillText("Player 2 Won!", canvas.width/2 + 50, 100);	
				}

				canvasContext.fillText("Click to continue", canvas.width/2 + 10, canvas.height-100);
				
				return;
			}
			updatePositions();
			drawEverything();
		}, 1000/fps);
}

function drawEverything() {
	canvasContext.font = "20px Verdana";
	
	// Background
	drawRect(0, 0, canvas.width, canvas.height, 'black');

	// Paddles
	drawRect(0, player1Y, PADDLE_WIDTH, PADDLE_HEIGHT, 'white');
	drawRect(canvas.width-10, player2Y, PADDLE_WIDTH, PADDLE_HEIGHT, 'white');

	// Net
	for (var i = 0; i < canvas.height; i += 40) {
		drawRect(canvas.width/2 - 1, i, 2, 20, 'white');
	}

	// Ball
	canvasContext.fillStyle = 'white';
	canvasContext.beginPath();
	canvasContext.arc(ballX, ballY, 10, 0, Math.PI*2, true);
	canvasContext.fill();

	// Score
	canvasContext.fillText(player1Score, canvas.width/4, 100);
	canvasContext.fillText(player2Score, (canvas.width/4)*3, 100);
}

function drawRect(x, y, width, height, colour) {
	canvasContext.fillStyle = colour;
	canvasContext.fillRect(x, y, width, height);
}

function updatePositions() {
	if (ballY <= 10 || ballY >= canvas.height-10) {
		ballSpeedY = -ballSpeedY;
	}

	// opponent AI
	if ((player2Y + PADDLE_HEIGHT/2)-35 > ballY && player2Y >= 0) {
		player2Y -= PADDLE2_SPEED;
	} else if ((player2Y - PADDLE_HEIGHT/2)+35 < ballY && player2Y <= canvas.height - PADDLE_HEIGHT) {
		player2Y += PADDLE2_SPEED;
	}

	// Check ball off screen
	if (ballX < 10 || ballX+10 > canvas.width-10) {
		if (ballY > player1Y && ballY < player1Y + PADDLE_HEIGHT && ballX < canvas.width/2) {
			ballSpeedX = -ballSpeedX;

			var deltaY = ballY - (player1Y+PADDLE_HEIGHT/2);
			ballSpeedY = deltaY*0.1;
		}
		else if (ballY > player2Y && ballY < player2Y + PADDLE_HEIGHT && ballX > canvas.width/2) {
			ballSpeedX = -ballSpeedX;

			var deltaY = ballY - (player2Y+PADDLE_HEIGHT/2);
			ballSpeedY = deltaY*0.1;
		}
		else {
			scoreCounter();
			ballReset();
		}
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

function ballReset() {
	ballSpeedX = -ballSpeedX;
	ballY = canvas.height/2;
	ballX = canvas.width/2;
}

function scoreCounter() {
	if (ballX > canvas.width/2) {
		player1Score++;
	}
	else if (ballX < canvas.width/2) {
		player2Score++;
	}

	if (player1Score == 3 || player2Score == 3) {
		showWinScreen = true;
	}
}

function mouseClick(evt) {
	if (showWinScreen) {
		player1Score = 0;
		player2Score = 0;
		showWinScreen = false;
	}
}