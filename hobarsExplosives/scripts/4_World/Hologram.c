modded class Hologram
{
	override void UpdateHologram(float timeslice)
	{
		// Check if projected item is a Plastic_Explosive
		Plastic_Explosive explosive_HBE = Plastic_Explosive.Cast(m_Projection);
		if (!explosive_HBE)
		{
			super.UpdateHologram(timeslice);
			return;
		}

		// Require duct tape in the TapeSlot
		if (!explosive_HBE.FindAttachmentBySlotName("TapeSlot"))
		{
			super.UpdateHologram(timeslice);
			return;
		}

		// Raycast from player's head position forward
		vector from_HBE;
		MiscGameplayFunctions.GetHeadBonePos(m_Player, from_HBE);
		vector camDir_HBE = GetGame().GetCurrentCameraDirection();
		vector to_HBE = from_HBE + camDir_HBE * 2.0;

		vector contactPos_HBE, contactNorm_HBE;
		float hitFraction_HBE;
		Object hitObject_HBE;

		// Allow placement on most physical surfaces
		int mask = PhxInteractionLayers.BUILDING 
				 | PhxInteractionLayers.VEHICLE
				 | PhxInteractionLayers.ITEM_LARGE
				 | PhxInteractionLayers.TERRAIN
				 | PhxInteractionLayers.DYNAMICITEM
				 | PhxInteractionLayers.FENCE
				 | PhxInteractionLayers.FIREGEOM;

		if (DayZPhysics.RayCastBullet(from_HBE, to_HBE, mask, m_Player, hitObject_HBE, contactPos_HBE, contactNorm_HBE, hitFraction_HBE))
		{
			m_Projection.SetPosition(contactPos_HBE);
			m_Projection.SetOrientation(vector.Direction(contactNorm_HBE, "0 1 0"));
			m_Projection.SetInvisible(false);
			return;
		}

		// Hide projection if nothing was hit
		m_Projection.SetInvisible(true);
	}
}
