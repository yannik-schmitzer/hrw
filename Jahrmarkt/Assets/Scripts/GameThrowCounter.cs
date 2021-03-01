using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameThrowCounter : MonoBehaviour
{
    public int ThrowCount;
    public ThrowCounter One;
    public ThrowCounter Two;
    public ThrowCounter Three;
    public ThrowCounter Four;
    public ThrowCounter Five;
    public ThrowCounter Six;
    public ThrowCounter Seven;
    public ThrowCounter Eight;
    public ThrowCounter Nine;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        ThrowCount = One.ThrowCount + Two.ThrowCount + Three.ThrowCount + Four.ThrowCount + Five.ThrowCount + Six.ThrowCount + Seven.ThrowCount + Eight.ThrowCount + Nine.ThrowCount;
    }
}
