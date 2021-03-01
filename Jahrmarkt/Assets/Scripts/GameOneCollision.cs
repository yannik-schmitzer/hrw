using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameOneCollision : MonoBehaviour
{
    public int ScoreCount;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Ground")
        {
            ScoreCount = ScoreCount + 1;
            gameObject.GetComponent<Rigidbody>().constraints = RigidbodyConstraints.FreezeAll;
            gameObject.GetComponent<MeshCollider>().enabled = false;
        }
    }
}
