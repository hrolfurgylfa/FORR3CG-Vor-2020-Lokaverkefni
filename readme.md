# FORR3CG - Lokaverkefni
Þetta GitHub repository geymir lokaverkefni í C++ forritun gert í Tækniskólanum, verkefnið er að gera forrit með notandaviðmóti sem geymir bækur, myndbönd og tímarit. [Verkefnalýsing](https://github.com/gestskoli/FORR3CGV20_Lokaverkefni/blob/master/README.md#forr3cg-vor-2020---lokaverkefni-35)

Dagbók
------

### 15/4/2020
Í dag vann ég á grunn gagna klösunum sem eru Efnis klasinn sem hinir klasarnir byggja frá og svo Bok, Myndband og Timarit sem eru klasarnir sem erfa frá Efni. Þessir klasar ættu núna allir að vera tilbúnir vegna þess að það er komin print function í alla klasana og extra gögnin í Bok, Myndband og Timarit miðað við Efni. Ég gleymdi reyndar að pusha svo að pushið er degi seint.

### 16/4/2020
Í dag byrjaði ég að breyta linked listanum sem ég var með í Skilaverkefni 2 í hash töflu, hash fallið er það eina sem er tilbúið en ég hef ekki enþá prufað það svo að það gæti verið vandamál með það. Nodeið sem ég mun nota í hash töflunni er núna líka tilbúið. Ég er líka búinn að ákveða að nota heitin sem aðal valueið, ekki ID vegna þess að hash tafla fyrir ID er óþarfi og gerir forritið bara hægara. Ég gleymdi samt aftur að pusha breytingunum svo að pushið kom daginn eftir.

### 17/4/2020
Í dag, eða nótt vann ég aðeins við að laga allskonar föll í hash töflunni og svo vann ég á föllunum hash_table.visualize og efni.get_eight_letters hash_table.visualize ætti að vera komið en ég mun þurfa að kíkja aftur á efni.get_eight_letters þegar ég er búinn með utf8 föllin.

Það sem ég eyddi mestum tíma í var að vinna á bit operations fyrir utf8_string_length fallið. Það er núna tilbúið en þá er næsta skref að gera utf8_string_index, það verður mun flóknara vegna þess að ég get ekki bara hent út continuation bytum heldur þarf ég að reikna út hversu mörg þannig eru og skila þeim með svo að ég skili ekki ólesanlegum stöfum.

Það sem tók lengstan tíma við utf8_string_length var bæði það að skilja vel hvernig utf8 skiptir stöfunum upp í byte en ég fann heppilega [gott myndband frá Tom Scott sem útskýrir utf8 vel](https://youtu.be/MijmeoH9LT4) og það að fatta að af eitthverri ástæðu er hægt að vera með signed char, en ég hélt að char væri alltaf unsigned.

### 20/4/2020
Í dag byrjaði ég á að klára UTF-8 föllin, ég endurskrifaði líka svolítið fallið sem ég kláraði síðast til þess að endurtaka mig minna. Svo eftir það fór ég að klára visualize fallið sem ég get núna klárað með utf8 föllunum.

### 27/4/2020
Í dag færði ég dagbókina og fraKennara skjölin inn í eitt readme skjal, ég bætti svo líka við einfaldri lýsingu á verkefninu og lista af aukakröfum sem ég hef gert í readme skjalið.

Aukakröfur gerðar
------

* Búið til föll sem finna hversu margir stafir eru í streng og skila staf af ákveðnum index sem virka rétt með UTF-8 stöfum, þau klippa UTF-8 stafi ekki í sundur eins og venjulegu strengjavinnslu föllin. [Skoða í dagbók](https://example.com)

Umsögn - Einkunn
------

### Hlutaskil

Þetta lítur allt mjög vel út hjá þér. Allt komið sem á að vera komið og rúmlega það. Góð dagbók.

Einkunn fyrir hlutaskil: 30/30
