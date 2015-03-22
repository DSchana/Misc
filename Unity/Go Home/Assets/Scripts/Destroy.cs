using UnityEngine;
using System.Collections;

public class Destroy : MonoBehaviour {
	public float lifeTime = 0f;
	// Use this for initialization
	void Start () {
		Destroy (gameObject, lifeTime);
	}
}
