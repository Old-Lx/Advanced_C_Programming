#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "./asm/avx/avx.h"

#include "./particle/particle.h"
#include "./particle/particle_ops.h"

#include "./vector/vector.h"
#include "./vector/vector_math.h"

// Sobre las ops de avx https://www.sciencedirect.com/science/article/pii/S2090447920300058#:~:text=Intel's%20AVX%20prescripts%20sets%20permitting%20one%20floating%2Dpoint,pairs%20of%20(64%2Dbit)%20floating%2D%20point%20numbers%20simultaneously.
// Resta de avx https://learn.microsoft.com/en-us/dotnet/api/system.runtime.intrinsics.x86.avx.subtract?view=net-10.0
// vpaddb https://uops.info/html-instr/VPADDB_YMM_YMM_YMM.html
// vpsubb https://www.felixcloutier.com/x86/psubb:psubw:psubd
// Sobre AVX2 https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.cai.sk/ojs/index.php/cai/article/download/2017_5_1001/851/10079&ved=2ahUKEwjn1eif9YOTAxXnXEEAHXnzDnEQFnoECE0QAQ&usg=AOvVaw3NeejGjkc0Uqiemrhh_4h_
// Lista de instrucciones AVX https://docs.oracle.com/cd/E36784_01/html/E36859/gntae.html

int main(){

    // Para crear números aleatorios
    srand(time(NULL));

    // Testing particles
    size_t n = 2;

    // Reservamos el espacio para un sistema de partículas
    s_particle* particles_system = particle_new(sizeof(uint8_t), sizeof(uint8_t), u8, u8, 2);

    // Reservamos el espacio para velocidad y posición de cada partícula
    s_vector* pos_particle1 = vector_new(sizeof(uint8_t), u8, 3);
    s_vector* vel_particle1 = vector_new(sizeof(uint8_t), u8, 3);

    s_vector* pos_particle2 = vector_new(sizeof(uint8_t), u8, 3);
    s_vector* vel_particle2 = vector_new(sizeof(uint8_t), u8, 3);

    // Generamos pseudo aleatoriamente los valores de cada partícula
    uint8_t test_pos_data1[] = {
        (rand() % 255), (rand() % 255), (rand() % 255)
    };
    uint8_t test_vel_data1[] = {
        (rand() % 255), (rand() % 255), (rand() % 255)
    };

    uint8_t test_pos_data2[] = {
        (rand() % 255), (rand() % 255), (rand() % 255)
    };
    uint8_t test_vel_data2[] = {
        (rand() % 255), (rand() % 255), (rand() % 255)
    };

    // Introducimos los valores en cada vector de posición y velocidad
    vector_push(pos_particle1, &test_pos_data1[0]);
    vector_push(pos_particle1, &test_pos_data1[1]);
    vector_push(pos_particle1, &test_pos_data1[2]);

    vector_push(pos_particle2, &test_pos_data2[0]);
    vector_push(pos_particle2, &test_pos_data2[1]);
    vector_push(pos_particle2, &test_pos_data2[2]);

    vector_push(vel_particle1, &test_vel_data1[0]);
    vector_push(vel_particle1, &test_vel_data1[1]);
    vector_push(vel_particle1, &test_vel_data1[2]);

    vector_push(vel_particle2, &test_vel_data2[0]);
    vector_push(vel_particle2, &test_vel_data2[1]);
    vector_push(vel_particle2, &test_vel_data2[2]);

    uint8_t pos1 = *(uint8_t *)vector_at(pos_particle1, 0);
    printf("pos 1 address: %d\n", pos1);

    // Introducimos cada partícula en el vector de partículas y el sistema de partículas
    particle_push(particles_system, pos_particle1, vel_particle1);
    particle_push(particles_system, pos_particle2, vel_particle2);

    s_vector* test_ptr = particle_at(particles_system, 0);
    uint8_t pos2 = *(uint8_t *)vector_at(particles_system->pos, 0);
    printf("pos 1 address: %d\n", pos2);



    // Generamos un vector de n partículas
    s_vector* particles_vector = n_particles_vector(n, particle_at(particles_system, 0), particle_at(particles_system, 1));

    /*if(!vector_empty(particles_vector)){
        printf("Vector size: %lu\n",vector_size(particles_vector));
    }*/

    // Distancia entre partículas
    size_t dist_btwn_particles = particle_absolute_distance(((s_particle *)particle_at(particles_system, 0))->pos, ((s_particle *)particle_at(particles_system, 1))->pos);

    printf("Distancia entre partículas de prueba: %ld\n", dist_btwn_particles);

    vector_erase(particles_vector, 1);

    // uint8_t test_ptr;
    vector_pop(particles_vector, (void*) &test_ptr);
    vector_pop(particles_vector, (void*) &test_ptr);
    vector_pop(particles_vector, (void*) &test_ptr);

    
    vector_delete(particles_vector);

    return 1;
}