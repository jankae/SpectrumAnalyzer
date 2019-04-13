#!/usr/bin/python

import visa

rm = visa.ResourceManager()
dev = rm.open_resource(rm.list_resources()[1])
dev.query("*IDN?")

