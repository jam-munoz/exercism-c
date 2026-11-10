def response(hey_bob: str) -> str:
    if not hey_bob.strip():
        return "Fine. Be that way!"
    
    hey_bob = hey_bob.strip()
    question = hey_bob.endswith('?')

    if question and hey_bob.isupper():
        return "Calm down, I know what I'm doing!"
    elif question:
        return "Sure."
    elif hey_bob.isupper():
        return "Whoa, chill out!"
    elif hey_bob.isspace():
        return "Fine. Be that way!"
    else:
        return "Whatever."
