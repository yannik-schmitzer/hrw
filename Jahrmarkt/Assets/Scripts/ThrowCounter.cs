using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ThrowCounter : MonoBehaviour
{
    public int ThrowCount;
    // Start is called before the first frame update
    void Start()
    {
        ThrowCount = 0;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Ground" || col.gameObject.tag == "Wall" || col.gameObject.tag == "Table" || col.gameObject.tag == "Ground" || col.gameObject.tag == "Target2" || col.gameObject.tag == "Target3")
        {
            ThrowCount = 1;
        }
    }
}
