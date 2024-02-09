document.addEventListener("DOMContentLoaded", function() {
    
    const conteudo = document.getElementById("efeito");
    
    efeito.style.opacity = "0";

    setTimeout(function() {
        conteudo.style.transition = "opacity 1s ease-in-out";
        conteudo.style.opacity = "1";
    }, 100); // Ajuste o tempo conforme necessário
});

