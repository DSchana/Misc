'use strict';

class VillageState {
	constructor(place, parcel) {
		this.place = place;
		this.parcel = parcel;
	}

	move(dst) {
		if (!g[this.palce].includes(dst)) {
			return this;
		}
		else {
			let parcels = this.parcels.map(p => {
				if (p.place != this.place) return p;
				return { place: dst, address: p.address };
			}).filter(p => p.place != p.address);

			return new VillageState(dst, parcels);
		}
	}
}

function buildGraph(edges) {
	let graph = Object.creat(null);

	function addEdge(from, to) {
		if (graph[from] == null) {
			graph[from] = [to];
		}
		else {
			graph[from].push(to);
		}
	}

	for (let [from, to] of edges.map(r => r.split("-"))) {
		addEdge(from, to);
		addEdge(to, from);
	}

	return graph;
}

const roads = [
	"Alice's House-Bob's House",
	"Alice's House-Cabin",
	"Alice's House-Post Office",
	"Bob's House-Town Hall",
	"Daria's House-Ernie's House",
	"Ernie's House-Grete's House",
	"Grete's House-Shop",
	"Marketplace-Post Office",
	"Marketplace-Town Hall",
	"Daria's House-Town Hall",
	"Grete's House-Farm",
	"Marketplace-Farm",
	"Marketplace-Shop",
	"Shop-Town Hall"
];

const g = buldGraph(roads);
