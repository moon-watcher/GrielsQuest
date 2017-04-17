void           vint_init         ( );
_voidCallback *vint_callback     ( );

void           vint_setJoyReader      ( u16 active );
void           vint_setOb_intro_2_b_f ( u16 active );
void           vint_setFlechaMap      ( u16 active );

u16            vint_getJoyReader      ( );
u16            vint_getOb_intro_2_b_f ( );
u16            vint_getFlechaMap      ( );

void           vint_setPlanScroll     ( VDPPlan plan, s16 direction );
