#===================================================================#
# RingQt Sample
# Print Date & Time (Including MilliSecond)
#===================================================================#

load "guilib.ring"

oTime = new QDateTime

? oTime.CurrentDateTime().toString("yyyy/MM/dd hh:mm:ss,zzz")
? oTime.CurrentDateTime().toString("zzz")

#===================================================================#
