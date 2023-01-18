a = [1,2,3]
? :one
a[1] = ref(a)
? :two
a[1] = ref(a)
? :three
a[1] = ref(a)
? :four
? refcount(a)
a[1] = NULL
? refcount(a)
? :done