# Author: Ilir Liburn

a = [ref(a)]

r = new Referer(a)
? r[1]
r = NULL
? a


class Referer
        data
        function init(data)
                this.data = data
        function operator(cOperator,vValue)
                switch cOperator
                        on "[]"
                                return & ref(this[vValue])

                off