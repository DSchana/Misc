// Recursion5.java
// This is brute force pathfinding where we simply check all possible paths
// don't try paths with more than 12 steps, they will take a very long time.
class Recursion5 {
	static void paths(int destX, int destY, String path, int currX, int currY, int steps){
		// Base case steps==0 Either we're there or we're not
		if(steps == 0){
			if(currX == destX && currY == destY){
				System.out.println(path);
			}
		}
		else{
			paths(destX, destY, path + "U", currX, currY+1, steps-1);
			paths(destX, destY, path + "D", currX, currY-1, steps-1);
			paths(destX, destY, path + "L", currX-1, currY, steps-1);
			paths(destX, destY, path + "R", currX+1, currY, steps-1);
		}
	}

	static void paths(int destX, int destY, int steps){
		paths(destX, destY, "", 0, 0, steps);
	}
			
	public static void main(String[] args){
		paths(3,2,7);
	}
}
