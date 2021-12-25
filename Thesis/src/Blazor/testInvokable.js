function showGeneratedMessage() {
    DotNet.invokeMethodAsync('Test', 'GenerateString')
        .then(data => {
            alert(data)
        });
}