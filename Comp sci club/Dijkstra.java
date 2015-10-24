import java.util.*;
import java.io.*;

public class Dijkstra {

	static class Edge implements Comparable<Edge> {
		public int cost, dest;
		Edge (int dest, int cost) {
			this.dest = dest;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge e) {
			return cost - e.cost;
		}
	}

	public static void main(String[] args) {
		ArrayList<ArrayList<Edge>> adj = new ArrayList<ArrayList<Edge>>();

		for (int i = 0; i < 6; ++i)
			adj.add(new ArrayList<Edge>());

		adj.get(1).add(new Edge(2, 3));
		adj.get(1).add(new Edge(3, 4));
		adj.get(2).add(new Edge(4, 2));
		adj.get(2).add(new Edge(5, 7));
		adj.get(3).add(new Edge(4, 9));
		adj.get(3).add(new Edge(5, 1));
		adj.get(4).add(new Edge(4, 100000));

		PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
		/*
		 * offer - add new item
		 * poll - get first item
		 */

		pq.offer(new Edge(1, 0));  // Starting node, costs 0 to get to it

		while (!pq.isEmpty()) {
			Edge curr = pq.poll();

			if (curr.dest == 4) {
				System.out.println(curr.cost);
				System.exit(1);
			}

			for (Edge e : adj.get(curr.dest))
				pq.offer(new Edge(e.dest, curr.cost + e.cost));
		}
	}
}