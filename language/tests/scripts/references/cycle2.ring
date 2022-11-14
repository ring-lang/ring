a = ["start"]
b = [:a = NULL, :c = "c"]
b[1][2] = ref(a)
? b[1][2][1]

a[:b] = NULL
a[2][2] = ref(B)

a[1] = "START"
? b[1][2][1]
