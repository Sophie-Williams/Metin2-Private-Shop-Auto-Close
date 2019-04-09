//1.) Search for:
    ch->Save();
//1.2) Add after:
#ifdef ENABLE_PRIVATE_SHOP_AUTO_CLOSE
	if (IsPCShop() && IsSoldOut())
	{
		m_pkPC->CloseMyShop();
		m_pkPC->ChatPacket(CHAT_TYPE_NOTICE, "Your store closed automatically, reason: sold out!");
	}
#endif

//2.1) Search for:
void CShop::SetPCShop(LPCHARACTER ch)
{
	m_pkPC = ch;
}
//2.2) Add after:
#ifdef ENABLE_PRIVATE_SHOP_AUTO_CLOSE
bool CShop::IsSoldOut()
{
	BYTE bItemCount = 0;
	for (size_t i = 0; i < m_itemVector.size() && i < SHOP_HOST_ITEM_MAX_NUM; ++i)
	{
		const SHOP_ITEM & r_item = m_itemVector[i];
		if (r_item.pkItem)
			++bItemCount;
	}
	
	return (bItemCount == 0);
}
#endif