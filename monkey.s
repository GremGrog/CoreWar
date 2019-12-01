.name "Stupid Monkey"
.comment "I'll get my own worldwide banana!!!!"

live:	live %1
		live %2
		live %3
		live %4
		zjmp %:attack

attack:	sti r1, %1024, %-24
		sti r1, %2048, %-24
		sti r1, %3064, %-48
		zjmp %:live
	
