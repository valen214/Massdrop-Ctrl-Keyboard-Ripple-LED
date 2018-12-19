


distance_map = {}


key_position = [
    [None] * 15,
    [None, None] + list("QWERTYUIOP") + [None] * 3,
    [None, None] + list("ASDFGHJKL") + [None] * 4,
    [None, None] + list("ZXCVBNM") + [None] * 6,
    [None] * 15,
]

x, y = 0, 0
while x < 15 and y < 5:
    sk = key_position[y][x]
    print(f"sk {sk} at ({x}, {y})")
    for i in range(0, 15):
        for j in range(0, 5):
            tk = key_position[j][i]
            if sk == tk or sk == None or tk == None: continue
            dis = abs(i - x) + abs(j - y)
            if i < x and j > y: dis -= abs(j - y)
            if sk not in distance_map:
                distance_map[sk] = {}
            if tk not in distance_map:
                distance_map[tk] = {}
            if tk not in distance_map[sk]:
                distance_map[sk][tk] = None
            if sk not in distance_map[tk]:
                distance_map[tk][sk] = None
            
            _dis = distance_map[sk][tk]
            if _dis and (_dis < dis):
                continue
            distance_map[sk][tk] = dis
            distance_map[tk][sk] = dis
            
    if x < 14:
        x += 1
    else:
        x = 0
        y += 1
    
print("DISTANCE MAP:")
print("\n".join([f"{k}: [{len(v)}]{(v.items())}" for k, v in distance_map.items()]))


valid = True
for k1, v in distance_map.items():
    for k2, d in v.items():
        if distance_map[k1][k2] != distance_map[k2][k1]:
            valid = False

if valid:
    print("valid result")
else:
    print("invalid result")