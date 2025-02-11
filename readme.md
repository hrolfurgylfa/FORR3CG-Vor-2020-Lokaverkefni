# FORR3CG - Lokaverkefni
Þetta GitHub repository geymir lokaverkefni í C++ forritun gert í Tækniskólanum, verkefnið er að gera forrit með notandaviðmóti sem geymir bækur, myndbönd og tímarit. [Verkefnalýsing](https://github.com/gestskoli/FORR3CGV20_Lokaverkefni/blob/master/README.md#forr3cg-vor-2020---lokaverkefni-35)


Skýrsla
------

Þetta var overall frekar skemmtilegt verkefni, ég æfði mig svolítið meira í C++ og lærði almennilega hvernig dictionaries virka.

Það voru samt leiðinda punktar, eins og vandamálin með [start gerðan rangan í headerinum](https://github.com/hrolfurgylfa/FORR3CG-Vor-2020-Lokaverkefni#0752020) og [þegar ég var að debugga getterana](https://github.com/hrolfurgylfa/FORR3CG-Vor-2020-Lokaverkefni#0752020) og af hverju þeir voru allir að skila Efni en ekki réttri gagnatípu. Þetta eru mestu ókostirnir við C++, að debugga það er ekki sérstaklega skemmtilegt vegna þess að maður þarf að filla allt af print skipunum til þess að finna hvar villan er.

Hins vegar voru mikið af skemmtilegum punktum, það er oft mjög satisfying þegar maður nær að koma flóknum kóða í gang í C++, sérstaklega þegar kóðinn virkar beint án neinna vandamála þótt að hann sé flókinn og maður búist við að hann bili. Þetta gerðist til dæmis við tafla.expand fallið mitt sem ég gerði [hér](https://github.com/hrolfurgylfa/FORR3CG-Vor-2020-Lokaverkefni#852020). Ég bjóst við að það myndi ekki virka í fyrstu tilraun en það virkaði fullkomlega.

### Virkni
Forritið virkar með RodudHashTafla klasanum í bakgrunnunum, hann gerir allt á bakvið UI-ið, þessi klasi er svo með array og í hverju array hólfi er RodudHashTofluNode sem geymir pointer á næsta stak í linked listanum og svo annan pointer á gögnin.

Gögnin eru alltaf geymd með pointer á þau í staðin fyrir að nota pass by reference svo að það sé hægt að setja inn klasa sem erfir frá Efni en ekki bara Efni klasann. Þetta gerir það að verkum að það er hægt að geyma Bækur, Myndbönd eða Tímarit í RodudHashTafla.

Til þess að minnka óþarfa og endurtekinn kóða taka bæti tafla.append og tafla.modify inn pointer að Efnis klasa, eða klasa sem erfir frá Efni sem input svo að ég þarf ekki að hafa margar functions fyrir þetta, append_bok, append_myndband og append_timarit heldur get ég bara haft append.

Myndband af virkni er fáanlegt [hérna](https://youtu.be/crA-d0MCz4A).

### Upplýsingar um viðmótið
Þetta forrit tekur nokrar einfaldar skipanir, í hjálp skipuninni þýðir venjulegur texti að það þarf að slá það inn eða ef það er skástrik er hægt að velja um nokkra valkosti en ef það eru hornsvigar utan um texta má setja orð að eigin vali þar svo eftir bandstrikið kemur lýsing á skipuninni.
```
help - Þessi skipun sýnir þessar hjálpar upplýsingar.

add [titill] bók/myndband/tímarit [höfundur/lengd/tölublað] - Setja inn bók/myndband/tímarit í safnið.
get [titill] - Sýnir hlutinn með nafninu sem þú slærð inn.

modify [titill] bók/myndband/tímarit [nýr titill] [nýr höfundur/ný lengd/nýtt tölublað] - Breyta bók/myndband/tímarit í safninu.
remove [titill] - Eyða hlut með þessu nafni úr safninu.

print - Prentar út allt í töflunni.
visualize - Sýnir allt í töflunni og í hvaða dálki það er.

exit - Loka forritinu.
```
Það er hægt að fá þessar upplýsingar inni í forritinu með því að ýta á enter án þess að slá neitt inn eða með því að slá inn help.


Aukakröfur
------

* Búið til föll sem finna hversu margir stafir eru í streng og skila staf af ákveðnum index sem virka rétt með UTF-8 stöfum, þau klippa UTF-8 stafi ekki í sundur eins og venjulegu strengjavinnslu föllin. [Skoða í dagbók](https://github.com/hrolfurgylfa/FORR3CG-Vor-2020-Lokaverkefni#1742020)
* Hash taflan stækkar sjálfkrafa þegar einn af linked listunum í henni fara yfir ákveðna lengd. [Skoða í dagbók](https://github.com/hrolfurgylfa/FORR3CG-Vor-2020-Lokaverkefni#852020)
* Hver linked list í hash töflunni byrjar alltaf á hæsta ID-inu og fer yfir í lægsta ID-ið í enda linked listans. Þetta var eitthvað sem kom úr Skilaverkefni 2 þegar ég breytti því yfir í hash töflu og ég gerði þetta á sama tíma og ég breytti Skilaverkefni 2 í hash töflu [hérna](https://github.com/hrolfurgylfa/FORR3CG-Vor-2020-Lokaverkefni#1642020).


Dagbók
------

### 15/4/2020
Í dag vann ég á grunn gagna klösunum sem eru Efnis klasinn sem hinir klasarnir byggja frá og svo Bok, Myndband og Timarit sem eru klasarnir sem erfa frá Efni. Þessir klasar ættu núna allir að vera tilbúnir vegna þess að það er komin print function í alla klasana og extra gögnin í Bok, Myndband og Timarit miðað við Efni. Ég gleymdi reyndar að pusha svo að pushið er degi seint.

### 16/4/2020
Í dag byrjaði ég að breyta linked listanum sem ég var með í Skilaverkefni 2 í hash töflu, hash fallið er það eina sem er tilbúið en ég hef ekki ennþá prufað það svo að það gæti verið vandamál með það. Nodeið sem ég mun nota í hash töflunni er núna líka tilbúið. Ég er líka búinn að ákveða að nota heitin sem aðal valueið, ekki ID vegna þess að hash tafla fyrir ID er óþarfi og gerir forritið bara hægara. Ég gleymdi samt aftur að pusha breytingunum svo að pushið kom daginn eftir.

### 17/4/2020
Í dag, eða nótt vann ég aðeins við að laga allskonar föll í hash töflunni og svo vann ég á föllunum hash_table.visualize og efni.get_eight_letters hash_table.visualize ætti að vera komið en ég mun þurfa að kíkja aftur á efni.get_eight_letters þegar ég er búinn með utf8 föllin.

Það sem ég eyddi mestum tíma í var að vinna á bit operations fyrir utf8_string_length fallið. Það er núna tilbúið en þá er næsta skref að gera utf8_string_index, það verður mun flóknara vegna þess að ég get ekki bara hent út continuation bytum heldur þarf ég að reikna út hversu mörg þannig eru og skila þeim með svo að ég skili ekki ólesanlegum stöfum.

Það sem tók lengstan tíma við utf8_string_length var bæði það að skilja vel hvernig utf8 skiptir stöfunum upp í byte en ég fann heppilega [gott myndband frá Tom Scott sem útskýrir utf8 vel](https://youtu.be/MijmeoH9LT4) og það að fatta að af einhverri ástæðu er hægt að vera með signed char, en ég hélt að char væri alltaf unsigned.

### 20/4/2020
Í dag byrjaði ég á að klára UTF-8 föllin, ég endurskrifaði líka svolítið fallið sem ég kláraði síðast til þess að endurtaka mig minna. Svo eftir það fór ég að klára visualize fallið sem ég get núna klárað með utf8 föllunum.

### 27/4/2020
Í dag færði ég dagbókina og fraKennara skjölin inn í eitt readme skjal, ég bætti svo líka við einfaldri lýsingu á verkefninu og lista af aukakröfum sem ég hef gert í readme skjalið.

Svo kom ég hash töfluni í gang, hún virkar núna með efnis klasanum og visualize fallið gerir það mikið auðveldara að sjá hvort að hash taflan sé að virka eða ekki.

### 29/4/2020
Í dag vann ég á því að breyta append inntakinu og RodudHashTafla arrayinum í pointera, þetta er ekki ennþá komið og ég er ennþá að reyna að leisa nokkur crashes en ég mun þurfa að gera það seinna.

### 07/5/2020
Í dag byrjaði ég á því að laga hash töfluna með hjálp kennarans, vandamálið var að ég var að búa pointerinn rangt til í headerinum.

Ég fór svo að vinna á leið til þess að sækja hluti úr hash töflunni með föllunum get_efni, get_bok, get_myndband og get_timarit. Þetta tók frekar langan tíma vegna þess að ég var lengi að klóra mér í hausnum yfir því að gögnin voru að missa allt nema gögnin sem eru geymd í efnis klasanum, svo þegar ég rak alla leiðina sem gagna klasarnir fara fattaði ég að Nodeið var ekki að geyma gögnin sem pointer og við það eyddust öll extra gögnin. Þetta var samt ekki búið þá vegna þess að ég var að eyða pointerunum í RodudHashTafla.append, þetta var vegna þess að ég notaði þá ekki í Nodeinu en núna þegar ég var farinn að nota þá gleymdi ég að eyða þessari delete skipun en þegar ég fattaði það var þetta allt komið.

Svo til þess að endurtaka mig minna gerði ég líka fallið RodudHashTafla.find_node, þetta er svipað og find_parent en er hentugra þegar mér vantar bara gögnin en ekki foreldrið vegna þess að find_parent skillar nullptr þegar það sem ég er að reyna að finna er fyrsta stakið í linked listanum.

Eftir þetta vann ég svo á því að laga destructorinn fyrir hash töfluna og finally klára RodudHashTafla.remove() fallið.

### 8/5/2020
Í dag vann ég á expand() fallinu sem stækkar hash töfluna og nokkrum öðrum föllum sem tékka á stærð hash töflunnar. Ég bætti svo líka við getter og setter fyrir bæði max_depth og expand_value vegna þess að það er safe að breyta þessum tölum on the fly af notenda klasans.

Svo splittaði ég main upp í tvö mismunandi föll kölluð test og user interface, user interface keyrir sem default en ef það er gert -t þegar forritið er keyrt keyrir test. Svo gerði ég meiri valkosti í tasks skránni svo að það sé hægt að velja hvort að test eða user interface sé keyrt.

Ég vann svo á user interfacinu, ég gat notað mest af grunn flight booking interfacinu en ég þurfti samt að breyta slatta til þess að það hagaði sér rétt. Svo ákvað ég líka að gera test part af user interfacinu svo að ef maður velur test keyrir prufu kóðinn minn fyrist og setur fullt inn í hash töfluna svo að það sé auðveldara að prufa skipanir eins og get, modify og remove.

Eftir þetta eyddi ég svo smá tíma í að reyna að crasha forritinu og að gera outputtið aðeins fallegra.

Ég var svo að vinna á að reyna að compila fyrir windows en mér tókst það ekki, ég mun mögulega reyna það aftur en ég ætla að klára myndbandið og skýrsluna áður en ég fer að reyna að compila fyrir windows aftur.


Umsögn - Einkunn
------

### Hlutaskil

Þetta lítur allt mjög vel út hjá þér. Allt komið sem á að vera komið og rúmlega það. Góð dagbók.

Einkunn fyrir hlutaskil: 30/30
