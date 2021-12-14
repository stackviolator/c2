import json

def xor(data):
    return bytearray(data[i] ^ ord("Q") for i in range(0, len(data)))

config = {}

config['Hostname'] = 'This is a tset'
config['Migrate'] = 'If you see this, it means that this was patched'

config = json.dumps(config).encode()
padding = b'\x00' * (2000 - len(config) - 1)

config = xor(config) + b"\xff" + padding

# Find {"Hostname"
with open('./bin/c2', 'rb') as binFile:
    byteData = bytearray(binFile.read())
binFile.close()
offset = byteData.find(b'{"Hostname"')

# Write data
with open('./bin/c2', 'r+b') as binFile:
    binFile.seek(offset)
    binFile.write(config)
