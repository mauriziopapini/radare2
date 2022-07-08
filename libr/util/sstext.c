/* radare - LGPL - Copyright 2021 - pancake */

#include <r_util.h>

typedef struct {
	char ch;
	const char *l[3];
} SevenSegments;

// seven segment ascii-art text
static const SevenSegments ss_lc[] = {
	{ '0', {" __ ",
		"| /|",
		"|/_|"}
	},
	{ '1', {"    ",
		"  | ",
		"  | "}
	},
	{ '2', {" __ ",
		" __|",
		"|__ "}
	},
	{ '3', {" __ ",
		" __|",
		" __|"}
	},
	{ '4', {"    ",
		"|__|",
		"   |"}
	},
	{ '5', {" __ ",
		"|__ ",
		" __|"}
	},
	{ '6', {" __ ",
		"|__ ",
		"|__|"}
	},
	{ '7', {" __ ",
		"   |",
		"   |"}
	},
	{ '8', {" __ ",
		"|__|",
		"|__|"}
	},
	{ '9', {" __ ",
		"|__|",
		" __|"}
	},
	{ '$', {" __ ",
		"||_ ",
		" _||"}
	},
	{ '_', {"    ",
		"    ",
		" __ "}
	},
	{ '.', {"    ",
		"    ",
		"  _ "}
	},
	{ ',', {"    ",
		"    ",
		" _  "}
	},
	{ '/', {"    ",
		"  / ",
		" /  "}
	},
	{ '%', {"    ",
		" O/ ",
		" /O "}
	},
	{ '=', {"    ",
		" __ ",
		" __ "}
	},
	{ '"', {" __ ",
		"    ",
		"    "}
	},
	{ '?', {" __ ",
		"  _|",
		" _\\ "}
	},
	{ '+', {"    ",
		" _|_",
		"  | "}
	},
	{ '-', {"    ",
		" __ ",
		"    "}
	},
	{ '*', {"    ",
		"_\\/_",
		" /\\ "}
	},
	{ '(', {" _  ",
		"|   ",
		"|_  "}
	},
	{ ')', {"  _ ",
		"   |",
		"  _|"}
	},
	{ '[', {" _  ",
		"|   ",
		"|_  "}
	},
	{ ']', {"  _ ",
		"   |",
		"  _|"}
	},
	{ '>', {"    ",
		"  \\ ",
		"  / "}
	},
	{ ' ', {"    ",
		"    ",
		"    "}
	},
	{ 'a', {"  _ ",
		"  _|",
		" /_|"}
	},
	{ 'b', {"    ",
		"|_  ",
		"|_\\ "}
	},
	{ 'c', {"    ",
		" __ ",
		"|__ "}
	},
	{ 'd', {"    ",
		"  _|",
		" /_|"}
	},
	{ 'e', {" _  ",
		"|_\\ ",
		"|__ "}
	},
	{ 'f', {" __ ",
		"|_  ",
		"|   "}
	},
	{ 'g', {" __ ",
		" \\_|",
		"|__|"}
	},
	{ 'h', {"    ",
		"|_  ",
		"| \\ "}
	},
	{ 'i', {"   ",
		" _ ",
		" | "}
	},
	{ 'j', {" __ ",
		"  | ",
		"|_| "}
	},
	{ 'k', {"    ",
		"|_/ ",
		"| \\ "}
	},
	{ 'l', {"    ",
		"    ",
		"|___"}
	},
	{ 'm', {"    ",
		"    ",
		"|\\/|"}
	},
	{ 'n', {"    ",
		" __ ",
		"|  |"}
	},
	{ 'o', {"    ",
		" __ ",
		"|__|"}
	},
	{ 'p', {" __ ",
		"|__|",
		"|   "}
	},
	{ 'q', {" __ ",
		"|__|",
		"  \\ "}
	},
	{ 'r', {" __ ",
		"|__|",
		"| \\ "}
	},
	{ 's', {"    ",
		"  _ ",
		" _\\"}
	},
	{ 't', {"    ",
		"_|_ ",
		" |__"}
	},
	{ 'u', {"    ",
		"    ",
		"|__|"}
	},
	{ 'v', {"    ",
		"|  |",
		" \\/ "}
	},
	{ 'w', {"    ",
		"    ",
		"|/\\|"}
	},
	{ 'x', {"    ",
		" \\/ ",
		" /\\ "}
	},
	{ 'y', {"    ",
		" \\_|",
		"  _|"}
	},
	{ 'z', {"    ",
		" _  ",
		" /_ "}
	},
	{ '\0', {0}}
};

static const SevenSegments ss[] = {
	{ '0', {" __ ",
		"|  |",
		"|__|"}
	},
	{ '1', {"    ",
		"  | ",
		"  | "}
	},
	{ '2', {" __ ",
		" __|",
		"|__ "}
	},
	{ '3', {" __ ",
		" __|",
		" __|"}
	},
	{ '4', {"    ",
		"|__|",
		"   |"}
	},
	{ '5', {" __ ",
		"|__ ",
		" __|"}
	},
	{ '6', {" __ ",
		"|__ ",
		"|__|"}
	},
	{ '7', {" __ ",
		"   |",
		"   |"}
	},
	{ '8', {" __ ",
		"|__|",
		"|__|"}
	},
	{ '9', {" __ ",
		"|__|",
		" __|"}
	},
	{ '$', {" __ ",
		"||_ ",
		" _||"}
	},
	{ '_', {"    ",
		"    ",
		" __ "}
	},
	{ '.', {"    ",
		"    ",
		"  _ "}
	},
	{ ',', {"    ",
		"    ",
		" _  "}
	},
	{ '/', {"    ",
		"  / ",
		" /  "}
	},
	{ '%', {"    ",
		" O/ ",
		" /O "}
	},
	{ '=', {"    ",
		" __ ",
		" __ "}
	},
	{ '"', {" __ ",
		"    ",
		"    "}
	},
	{ '?', {" __ ",
		"  _|",
		" _\\ "}
	},
	{ '+', {"    ",
		" _|_",
		"  | "}
	},
	{ '-', {"    ",
		" __ ",
		"    "}
	},
	{ '*', {"    ",
		"_\\/_",
		" /\\ "}
	},
	{ '(', {" _  ",
		"|   ",
		"|_  "}
	},
	{ ')', {"  _ ",
		"   |",
		"  _|"}
	},
	{ '[', {" _  ",
		"|   ",
		"|_  "}
	},
	{ ']', {"  _ ",
		"   |",
		"  _|"}
	},
	{ '>', {"    ",
		"  \\ ",
		"  / "}
	},
	{ ' ', {"    ",
		"    ",
		"    "}
	},
	{ 'a', {" __ ",
		"|__|",
		"|  |"}
	},
	{ 'b', {"    ",
		"|__ ",
		"|__|"}
	},
	{ 'c', {"    ",
		" __ ",
		"|__ "}
	},
	{ 'd', {"    ",
		" __|",
		"|__|"}
	},
	{ 'e', {" __ ",
		"|_  ",
		"|__ "}
	},
	{ 'f', {" __ ",
		"|_  ",
		"|   "}
	},
	{ 'g', {" __ ",
		"| _ ",
		"|__|"}
	},
	{ 'h', {"    ",
		"|__|",
		"|  |"}
	},
	{ 'i', {" ___",
		"  | ",
		" _|_"}
	},
	{ 'j', {" __ ",
		"  | ",
		"|_| "}
	},
	{ 'k', {"    ",
		"|_/ ",
		"| \\ "}
	},
	{ 'l', {"    ",
		"|   ",
		"|__ "}
	},
	{ 'm', {"    ",
		"|\\/|",
		"|  |"}
	},
	{ 'n', {"    ",
		"|\\ |",
		"| \\|"}
	},
	{ 'o', {" __ ",
		"|  |",
		"|__|"}
	},
	{ 'p', {" __ ",
		"|__|",
		"|   "}
	},
	{ 'q', {" __ ",
		"|__|",
		"  \\ "}
	},
	{ 'r', {" __ ",
		"|__|",
		"| \\ "}
	},
	{ 's', {" __ ",
		"|__ ",
		" __\\"}
	},
	{ 't', {"    ",
		"_|_ ",
		" |_ "}
	},
	{ 'u', {"    ",
		"    ",
		"|__|"}
	},
	{ 'v', {"    ",
		"|  |",
		" \\/ "}
	},
	{ 'w', {"    ",
		"|  |",
		"|/\\|"}
	},
	{ 'x', {"    ",
		" \\/ ",
		" /\\ "}
	},
	{ 'y', {"    ",
		"|__|",
		" __|"}
	},
	{ 'z', {" __ ",
		"  / ",
		" /_ "}
	},
	{ '\0', {0}}
};

R_API char *r_str_ss(const char* msg, const char *nl, int cs) {
	if (!nl) {
		nl = "\n";
	}
	int i, j, n;
	RStrBuf *sb = r_strbuf_new ("");
	char *omsg = strdup (msg);
	RList *lines = r_str_split_list (omsg, "\n", 0);
	RListIter *iter;
	r_list_foreach (lines, iter, msg) {
		for (i = 0; i < 3; i++) {
			for (n = 0; msg[n]; n++) {
				char ch = tolower (msg[n]);
				if (cs && ch == msg[n]) {
					for (j = 0; ss_lc[j].ch; j++) {
						if (ss_lc[j].ch == ch) {
							r_strbuf_append (sb, ss_lc[j].l[i]);
							break;
						}
					}
				} else {
					for (j = 0; ss[j].ch; j++) {
						if (ss[j].ch == ch) {
							r_strbuf_append (sb, ss[j].l[i]);
							break;
						}
					}
				}
			}
			r_strbuf_append (sb, nl);
		}
		r_strbuf_append (sb, nl);
	}
	char *res = r_strbuf_drain (sb);
	r_list_free (lines);
	free (omsg);
	return res;
}
