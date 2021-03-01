using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;

public class TeleportHandling : MonoBehaviour
{
    public XRController leftTeleportRay;
    public XRController rightTeleportRay;
    public InputHelpers.Button teleportActivationButton;
    public GameObject TeleportReticle;

    // Start is called before the first frame update
    void Start()
    {
        rightTeleportRay.gameObject.SetActive(false);
        leftTeleportRay.gameObject.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        if (CheckIfActivated(rightTeleportRay))
        {
            leftTeleportRay.gameObject.SetActive(false);
            rightTeleportRay.gameObject.SetActive(true);
        }
        if (CheckIfActivated(leftTeleportRay))
        {
            leftTeleportRay.gameObject.SetActive(true);
            rightTeleportRay.gameObject.SetActive(false);
        }
        if (!CheckIfActivated(leftTeleportRay) && !CheckIfActivated(rightTeleportRay))
        {
            leftTeleportRay.gameObject.SetActive(false);
            rightTeleportRay.gameObject.SetActive(false);
            TeleportReticle.SetActive(false);
        }
        if (CheckIfActivated(leftTeleportRay) && CheckIfActivated(rightTeleportRay))
        {
            leftTeleportRay.gameObject.SetActive(false);
            rightTeleportRay.gameObject.SetActive(false);
            TeleportReticle.SetActive(false);
        }
    }

    public bool CheckIfActivated(XRController controller)
    {
        InputHelpers.IsPressed(controller.inputDevice, teleportActivationButton, out bool isActivated);
        return isActivated;
    }
}
