#pragma once


class CTClientUIBase : public TFrame
{
public:
	static BYTE m_bDragLock;
	static void ResetBasis( INT nWidth, INT nHeight);
	static CPoint m_vBasis[9];
	static CPoint m_vDefaultBASIS[9];
	static CRect m_rtDEFAULT_SCREEN;
	static CRect GetScreenRect();
	// Arab Ver.
	static CPoint GetUIBasisPos( DWORD dwBasisPoint, CPoint vOffset, CRect rc);
	static void GetUIOffset( CRect rtScreen, CRect rtComp, TFRAMEOFFSET* pFRAMEOFFSET );
	static DWORD GetGaugeDirection(DWORD dwOriginalDirection);
	// Arab Ver.
	static BYTE GetBasis(BYTE bBasisPoint);
	static CPoint GetOffset(CPoint pt, CRect rc);
	static CPoint GetFlipPos( TComponent *pCOMP, TComponent *pBASE);
	static void FlipControl(TComponent* pCOMP);

public:
	BYTE m_bDropTarget;
	BYTE m_bCanDrag;
	CPoint m_ptDrag;
	CRect m_rcDrag;
	BYTE m_bDraging;
	BYTE m_bBasisPoint;
	BOOL m_bUseBasis;
	CPoint m_vCompOffset;

public:
	virtual void OnLButtonDown(UINT nFlags, CPoint pt);
	virtual void OnLButtonUp(UINT nFlags, CPoint pt);
	virtual void OnMouseMove(UINT nFlags, CPoint pt);

	virtual ITDetailInfoPtr GetTInfoKey( const CPoint& point );
	virtual BOOL GetTChatInfo( const CPoint& point, TCHATINFO& outInfo );

	virtual TDROPINFO OnDrop( CPoint point);
	virtual BYTE OnBeginDrag(
		LPTDRAG pDRAG,
		CPoint point);

	virtual UINT GetUniqueID();
	virtual BOOL CanWithItemUI();
	virtual BOOL CanDisable();
	virtual	void DefaultPosition( CPoint* vBASIS, BOOL bRestore );
	virtual void ResetPosition();
	virtual void MoveComponent( CPoint pt );

	// Arab Ver.
	virtual BYTE GetBasis();
	virtual void SetBasis( BYTE bBasisID);
	virtual CPoint GetOffset();
	virtual void SetOffset( CPoint vOffset);

public:
	CTClientUIBase( TComponent *pParent, LP_FRAMEDESC pDesc);
	virtual ~CTClientUIBase();
};
