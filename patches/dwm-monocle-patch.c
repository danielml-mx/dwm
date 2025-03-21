// snippet of refactored monocle() function, to support gaps on monocle layout too
// just substitute the monocle() function located on your dwm.c file to this snippet
// this change requires vanity-gaps patch on your dwm build - https://dwm.suckless.org/patches/vanitygaps/
// disable/enable gaps and gaps controls work just like in tile layout
// credits to breakfict for this contribution: https://www.reddit.com/r/suckless/comments/m88dwg/monocle_gaps/grxs54k/?context=3

void
monocle(Monitor *m)
{
	unsigned int n = 0, oe = enablegaps;
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 0)
		return;

	if (smartgaps == n) {
		oe = 0; // outer gaps disabled
	}
	
	n = 0;

	for (c = m->clients; c; c = c->next)
		if (ISVISIBLE(c))
			n++;
			if (n > 0) /* override layout symbol */
				snprintf(m->ltsymbol, sizeof m->ltsymbol, "[%d]", n);
				int newx, newy, neww, newh;

				for (c = nexttiled(m->clients); c; c = nexttiled(c->next)) {
					if (m->gappoh == 0) {
						newx = m->wx - c->bw;
						newy = m->wy - c->bw;
						neww = m->ww;
						newh = m->wh;
					} else {
						newx = m->wx + m->gappoh*oe - c->bw;
						newy = m->wy + m->gappoh*oe - c->bw;
						neww = m->ww - 2 * (m->gappoh*oe + c->bw);
						newh = m->wh - 2 * (m->gappoh*oe + c->bw);
					}
					applysizehints(c, &newx, &newy, &neww, &newh, 0);
					if (neww < m->ww)
						newx = m->wx + (m->ww - (neww + 2 * c->bw)) / 2;
					if (newh < m->wh)
						newy = m->wy + (m->wh - (newh + 2 * c->bw)) / 2;
						resize(c, newx, newy, neww, newh, 0);
				}

}