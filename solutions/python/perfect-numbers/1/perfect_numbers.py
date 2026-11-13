def classify(number):
    """ A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """
    if number < 1:
        raise ValueError("Classification is only possible for positive integers.")
    elif number < 5:
        return "deficient"
    aliquot = 1
    for i in range(2, number):
        if number % i == 0:
           aliquot += i
    if aliquot == number:
        return "perfect"
    elif aliquot > number:
        return "abundant"
    return "deficient"