增加一个控件时，需要在XM_rtti里新增一个elseif，同时在XM_Base里新增一个include。


Q：为什么用作rtti的m_strName，只能在namemap里出现一次，多一次就会assert
A：应该是在rtti。cpp初始化的时候加入列表，要生成什么控件再从里面拿。但是把实例化的类放进去有且只有一次又挺奇怪的，可能m_strname本意是用来查找控件而不是rtti，但现在通过ID_Lobby
里的Id识别控件。
更好的方式是用prototype，写好一个regitercontrol（name,lpCreateFun）,加CreateControl，以及一个<name,*void>的map.

Q：static控件干嘛用的
不清楚，不过static确实没用

UI_EnumTypes.h迟早要把它清空
有下划线说明禁止控件里直接引用

Q:UICtrl.h和UI_Control的区别

把鼠标键盘事件做成信号槽


废弃controltype，rtti足够用了

font 似乎有重复渲染quechar一次，end另一次，in drawTextW

GetGlyphOutline取字形，成为一个bimap型的texture，传入fonttexture