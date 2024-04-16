import settings

def height_prcnt(percentage):
    return (settings.HEIGHT / 100) * percentage

def width_prcnt(percentage):
    return (settings.WIDTH / 100) * percentage

print(height_prcnt(25))