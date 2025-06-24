modded class Hologram
{
	override void UpdateHologram(float timeslice)
	{
		// Only intercept if the projection is a Plastic_Explosive
		Plastic_Explosive explosive = Plastic_Explosive.Cast(m_Projection);
		if (!explosive)
		{
			super.UpdateHologram(timeslice);
			return;
		}

		// If duct tape is attached, skip vanilla hologram logic — custom ActionDeploy handles placement visuals
		if (explosive.FindAttachmentBySlotName("TapeSlot"))
		{
			return;
		}

		// No duct tape → fallback to normal ground-only hologram
		super.UpdateHologram(timeslice);
	}
}

