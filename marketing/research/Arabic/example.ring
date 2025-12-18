ChangeRingKeyword put     اطبع
ChangeRingKeyword get     ادخل
ChangeRingKeyword if      لو
ChangeRingKeyword elseif  امالو
ChangeRingKeyword else    عداذلك
ChangeRingKeyword endif   تمام

سطرجديد = nl

اطبع "أهلا ومرحبا بكم معنا" + سطرجديد
اطبع "من فضلك ... كم عمرك؟" + سطرجديد
ادخل العمر
العمر = 0 + العمر
لو العمر < 10
    اطبع "عمرك اقل من 10 سنوات" + سطرجديد
امالو العمر < 30
    اطبع "عمرك اكبر من او يساوي 10 سنوات و اقل من 30 عاما" + سطرجديد
عداذلك
    اطبع "العمر اكبر من او يساوي 30 عاما"
تمام
